void infix_to_postfix(char *infix)
//void infix_to_postfix(HWND hwnd, UINT message, UINT wParam, long lParam)
{
char *postfix="";
char operators[50]="";
int p=0,i=0,o=0,switcher=-1;

postfix=(char *)malloc(strlen(infix));
memset(postfix,0,sizeof(postfix));
	while(infix[i]!=0)
	{
		if((infix[i]>='0' && infix[i]<='9') || infix[i]=='.' )
		switcher=0;
		
		if( infix[i]=='+' ||infix[i]=='-')
		switcher='+';
		
		if( infix[i]=='*' || infix[i]=='/')
		switcher='*';		
		
		if (infix[i]=='^')
		switcher='^';
		
		if (infix[i]=='!')
		switcher='!';
	
		switch (switcher)
		{
			case 0://case of numbers 0123456789
			if(i!=0
//New number started
			&&	( (infix[i-1]<'0' || infix[i-1]>'9') && infix[i-1]!='.')
//Last symbol in postfix was a number
			&&	(postfix[p-1]>='0' && postfix[p-1]<='9') )
			{
			postfix[p]=' ';
			p++;
			}
			postfix[p]=infix[i];
			p++;
			i++;

			break;
			case'-':
			case '+':// +- +- +- +-
				if(operators[o-1]=='+' || operators[o-1] =='-' ||o == 0)
				{
				operators[o]=infix[i];
				o++;
				i++;
				}

				if(operators[o-1]=='*' || operators[o-1] =='/' || operators[o-1] =='^')
				{
					while(o-1 != -1)
					{
					postfix[p]=operators[o-1];	
					p++;
					operators[o-1]=0;
					o--;
					}
				operators[o]=infix[i];
				i++;
				o++;
				}
			break;

			case'/':
			case '*':
				if(operators[o-1]=='+' || operators[o-1] =='-' ||o == 0)
				{
				operators[o]=infix[i];
				o++;
				i++;
				}
				else if(operators[o-1]=='*' || operators[o-1] =='/' || operators[o-1] =='^')
				{
				postfix[p]=operators[o-1];
				o--;
				p++;
				operators[o]=infix[i];
				o++;
				i++;
				}
			break;
	
			case '^':
				if( operators[o-1]=='+' || operators[o-1] =='-' ||o == 0 || operators[o-1]=='*' || operators[o-1] =='/')
				{
				operators[o]=infix[i];
				o++;
				i++;
				}
			break;

			case '!':
			postfix[p]=infix[i];
			p++;
			i++;	
			break;
		}
	}
	while(o-1 != -1)
	{
	postfix[p]=operators[o-1];	
	p++;
	o--;
	}
memset(infix,0,sizeof(infix));
strncpy(infix,postfix,i);

//SendDlgItemMessage(hwnd,10,WM_SETTEXT,0,(long)postfix);
}
