void infix_to_postfix(char *infix)
//void infix_to_postfix(HWND hwnd, UINT message, UINT wParam, long lParam)
{
//char *infix="11+12*13/14-15^16!";
//char *infix="";
//char *postfix=(char *) malloc(1000);
//char *operands=(char *) malloc(100);
char postfix[200]="";
char operators[200]="";
int p=0,i=0,o=0,switcher=-1;
//SendDlgItemMessage(hwnd,10,WM_GETTEXT,0,(long)infix);


//char *infix="11+12*13/14-15^16!";
//char *infix="1+11*33!-2/2^2*1";
//char *postfix=(char *) malloc(1000);
//char *operators=(char *) malloc(100);
//int p=0,i=0,o=0,switcher=-1;

	while(infix[i]!=0)
	{
		if((infix[i]>='0' && infix[i]<='9') || infix[i]=='.' )
		switcher=0;
		
//		switcher=infix[i];
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
//axali ricxvi daiwyo
			&&	( (infix[i-1]<'0' || infix[i-1]>'9') && infix[i-1]!='.')
//manamdec ricxvi ewera
			&&	(postfix[p-1]>='0' && postfix[p-1]<='9') )
			{
			postfix[p]=' ';
			p++;
			}
//"1+2!*3/2!"
//"1 2! 3* 2!/+"
			postfix[p]=infix[i];
			p++;
			i++;

			break;
			case '+':// +- +- +- +-
				if(operators[o-1]=='+' || operators[o-1] =='-' ||o == 0)
				{
				operators[o]=infix[i];
				o++;
				i++;
				}
//////
				if(operators[o-1]=='*' || operators[o-1] =='/' || operators[o-1] =='^')
				{
					while(o-1 != -1)
					{
					postfix[p]=operators[o-1];	
					p++;
					operators[o-1]=0;
					o--;
					}
//				memset(&operators,0,sizeof(operators));
				operators[o]=infix[i];
				i++;
				o++;
				}
			break;

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
//				fact(
//			break;
		}
	}
	while(o-1 != -1)
	{
	postfix[p]=operators[o-1];	
	p++;
	o--;
	}
memset(infix,0,sizeof(infix));
strcpy(infix,postfix);
//SendDlgItemMessage(hwnd,10,WM_SETTEXT,0,(long)postfix);
}
