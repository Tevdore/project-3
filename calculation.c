void postfix_calculation(char *postfix)
{
//char *postfix="1 2 3+4*+5 3!^";
char numbers[20][30];
char operators;
int N=0,n=0,o=0,p=0;
double d1,d2,result_double;
int switcher,k;
__int64 i1,i2,result_int64=1;

memset(&numbers,0,sizeof(numbers));

	while(postfix[p]!=0)
	{
		if( (postfix[p]>='0' && postfix[p]<='9') || postfix[p]=='.' )
//postfix "1 2 3+4*+5 6!^"
		{
		numbers[N][n]=postfix[p];
		n++;
		}
		else if(postfix[p]==' ')
		{
		N++;
		n=0;
		}
		else
		{
		operators=postfix[p];
//			if(n!=0)
//			N++;
		n=0;
		
		switcher=(char) operators;

		if(numbers[N][0]==0)
		N--;

			if(strlen(numbers[N-1])<19 && strlen(numbers[N])<19 && strchr(numbers[N-1],'.')==0 && strchr(numbers[N],'.')==0)
			{
			i2=_atoi64(numbers[N]);
			N--;
			i1=_atoi64(numbers[N]);

				switch (switcher)
				{
					case '+':
					{
					result_int64=i1+i2;
					memset(numbers[N+1],0,sizeof(numbers[N+1]));
					memset(&numbers[N],0,sizeof(numbers[N]));
					sprintf(numbers[N], "%Ld",result_int64);
					N++;
					break;
					
					}
					case '-':
					{
					result_int64=i1-i2;
					memset(numbers[N+1],0,sizeof(numbers[N+1]));
					memset(&numbers[N],0,sizeof(numbers[N]));
					sprintf(numbers[N], "%Ld",result_int64);
					N++;
					break;
					}
					case '*':
					{
					result_int64=i1*i2;
					memset(numbers[N+1],0,sizeof(numbers[N+1]));
					memset(&numbers[N],0,sizeof(numbers[N]));
					sprintf(numbers[N], "%ld",result_int64);
					N++;
					break;
					}
					case '/':
					{
					result_double=(double)i1/i2;
					memset(numbers[N+1],0,sizeof(numbers[N+1]));
					memset(&numbers[N],0,sizeof(numbers[N]));
					sprintf(numbers[N], "%0.16f",result_double);
						while(numbers[N][strlen(numbers[N])-1]=='0' ||numbers[N][strlen(numbers[N])-1]=='.')
						numbers[N][strlen(numbers[N])-1]=0;
					N++;
					break;
					}
					case '^':
					{
					for(result_int64=1,k=0;k<i2;k++)
					result_int64=result_int64*i1;
					memset(numbers[N+1],0,sizeof(numbers[N+1]));
					memset(&numbers[N],0,sizeof(numbers[N]));
					sprintf(numbers[N], "%Ld",result_int64);
					N++;
					break;
					}
			
					case '!':
					{
							for(result_int64=1;i2!=1;i2--)
							result_int64=result_int64*i2;
						
					memset(numbers[N+1],0,sizeof(numbers[N+1]));
					sprintf(numbers[N+1], "%I64u",result_int64);
					N+=2;
					break;
					}
				}
			}

			else if(strchr(numbers[N-1],'.')!=0 || strchr(numbers[N],'.')!=0)
			{
			d2= atof(numbers[N]);
			N--;
			d1= atof(numbers[N]);

				switch (switcher)
				{
					case '+':
					{
					result_double=d1+d2;
					memset(numbers[N+1],0,sizeof(numbers[N+1]));
					memset(&numbers[N],0,sizeof(numbers[N]));
					sprintf(numbers[N], "%0.16f",result_double);
						while(numbers[N][strlen(numbers[N])-1]=='0' || numbers[N][strlen(numbers[N])-1]=='.')
						numbers[N][strlen(numbers[N])-1]=0;
					N++;
					break;
					
					}
					case '-':
					{
					result_double=d1-d2;
					memset(numbers[N+1],0,sizeof(numbers[N+1]));
					memset(&numbers[N],0,sizeof(numbers[N]));
					sprintf(numbers[N], "%0.16f",result_double);
						while(numbers[N][strlen(numbers[N])-1]=='0' || numbers[N][strlen(numbers[N])-1]=='.')
						numbers[N][strlen(numbers[N])-1]=0;
					N++;
					break;
					}
					case '*':
					{
					result_double=d1*d2;
					memset(numbers[N+1],0,sizeof(numbers[N+1]));
					memset(&numbers[N],0,sizeof(numbers[N]));
					sprintf(numbers[N], "%0.16f",result_double);
						while(numbers[N][strlen(numbers[N])-1]=='0' || numbers[N][strlen(numbers[N])-1]=='.')
						numbers[N][strlen(numbers[N])-1]=0;
					N++;
					break;
					}
					case '/':
					{
					result_double=d1/d2;
					memset(numbers[N+1],0,sizeof(numbers[N+1]));
					memset(&numbers[N],0,sizeof(numbers[N]));
					sprintf(numbers[N], "%0.16f",result_double);
						while(numbers[N][strlen(numbers[N])-1]=='0' || numbers[N][strlen(numbers[N])-1]=='.')
						numbers[N][strlen(numbers[N])-1]=0;
					N++;
					break;
					}
				}//morcha switch
			}//morcha if
			
		}//morcha else
		p++;
	}//morcha while

memset(postfix,0,sizeof(postfix));
strcpy(postfix,numbers[0]);
}
