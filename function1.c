long proc_main_wnd (HWND hwnd, UINT message, UINT wParam, long lParam)
{
	switch(message)
	{
		case WM_CREATE:
		{
		HWND h=0;
		CreateWindow("edit","",WS_VISIBLE|WS_CHILD,0,0,400,30,
			hwnd,(HMENU)10,0,0);

		h=CreateWindow("button","Close",WS_VISIBLE|WS_CHILD,270,120,100,50
			,hwnd,(HMENU)30,0,0);
		
		CreateWindow("button","^",WS_VISIBLE|WS_CHILD,0,250,50,50
			,hwnd,(HMENU)'^',0,0);

		CreateWindow("button","0",WS_VISIBLE|WS_CHILD,50,250,50,50
			,hwnd,(HMENU)0,0,0);

		CreateWindow("button",".",WS_VISIBLE|WS_CHILD,100,250,50,50
			,hwnd,(HMENU)'.',0,0);

		CreateWindow("button","=",WS_VISIBLE|WS_CHILD,150,250,50,50
			,hwnd,(HMENU)'=',0,0);

		CreateWindow("button","1",WS_VISIBLE|WS_CHILD,0,200,50,50
			,hwnd,(HMENU)1,0,0);
		
		CreateWindow("button","2",WS_VISIBLE|WS_CHILD,50,200,50,50
			,hwnd,(HMENU)2,0,0);
		
		CreateWindow("button","3",WS_VISIBLE|WS_CHILD,100,200,50,50
			,hwnd,(HMENU)3,0,0);
		
		CreateWindow("button","+",WS_VISIBLE|WS_CHILD,150,200,50,50
			,hwnd,(HMENU)'+',0,0);
		
		CreateWindow("button","4",WS_VISIBLE|WS_CHILD,0,150,50,50
			,hwnd,(HMENU)4,0,0);
		
		CreateWindow("button","5",WS_VISIBLE|WS_CHILD,50,150,50,50
			,hwnd,(HMENU)5,0,0);
		
		CreateWindow("button","6",WS_VISIBLE|WS_CHILD,100,150,50,50
			,hwnd,(HMENU)6,0,0);

		CreateWindow("button","-",WS_VISIBLE|WS_CHILD,150,150,50,50
			,hwnd,(HMENU)'-',0,0);
		
		CreateWindow("button","7",WS_VISIBLE|WS_CHILD,0,100,50,50
			,hwnd,(HMENU)7,0,0);

		CreateWindow("button","8",WS_VISIBLE|WS_CHILD,50,100,50,50
			,hwnd,(HMENU)8,0,0);
		
		CreateWindow("button","9",WS_VISIBLE|WS_CHILD,100,100,50,50
			,hwnd,(HMENU)9,0,0);
		
		CreateWindow("button","X",WS_VISIBLE|WS_CHILD,150,100,50,50
			,hwnd,(HMENU)'X',0,0);
		
		CreateWindow("button","C",WS_VISIBLE|WS_CHILD,0,50,50,50
			,hwnd,(HMENU)'C',0,0);

		CreateWindow("button","!",WS_VISIBLE|WS_CHILD,50,50,50,50
			,hwnd,(HMENU)'!',0,0);
		
		CreateWindow("button","<---",WS_VISIBLE|WS_CHILD,100,50,50,50
			,hwnd,(HMENU)'D',0,0);
		
		CreateWindow("button","/",WS_VISIBLE|WS_CHILD,150,50,50,50
			,hwnd,(HMENU)'/',0,0);
	
		}
		break;

		case WM_COMMAND:
	
			switch(LOWORD(wParam))
			{
			static int c=0;

				case '+':					
					if(HIWORD(wParam) == BN_CLICKED)
					{
					char str[256]="";
					c=0;
					
					SendDlgItemMessage(hwnd,10,WM_GETTEXT,sizeof(str),(long)str);		
						if(str[strlen(str)-1]=='+' ||str[strlen(str)-1]=='-' ||str[strlen(str)-1]=='*' ||str[strlen(str)-1]=='/'||str[strlen(str)-1]=='^')
						str[strlen(str)-1]=0;					
						if(str[strlen(str)-1] != '+' && str[strlen(str)-1]>=48 &&str[strlen(str)-1]<= 57 || str[strlen(str)-1] == '!')
						{	
						strcat(str,"+");
						SendDlgItemMessage(hwnd,10,WM_SETTEXT,0,(long)str);		
						}
					}
				break;
								
				case '-':					
					if(HIWORD(wParam) == BN_CLICKED)
					{
					char str[256]="";
					c=0;
					SendDlgItemMessage(hwnd,10,WM_GETTEXT,sizeof(str),(long)str);		
						if(str[strlen(str)-1]=='+' ||str[strlen(str)-1]=='-' ||str[strlen(str)-1]=='*' ||str[strlen(str)-1]=='/'||str[strlen(str)-1]=='^')
						str[strlen(str)-1]=0;					
						if(str[strlen(str)-1] != '-' && str[strlen(str)-1]>=48 &&str[strlen(str)-1]<= 57 || str[strlen(str)-1] == '!')
						{	
						strcat(str,"-");
						SendDlgItemMessage(hwnd,10,WM_SETTEXT,0,(long)str);		
						}
				}
				break;

				case 'X':					
					if(HIWORD(wParam) == BN_CLICKED)
					{
					char str[256]="";
					c=0;
					SendDlgItemMessage(hwnd,10,WM_GETTEXT,sizeof(str),(long)str);		
						if(str[strlen(str)-1]=='+' ||str[strlen(str)-1]=='-' ||str[strlen(str)-1]=='*' ||str[strlen(str)-1]=='/' ||str[strlen(str)-1]=='^')
						str[strlen(str)-1]=0;					
						if(str[strlen(str)-1] != 'X' && str[strlen(str)-1]>=48 &&str[strlen(str)-1]<= 57 || str[strlen(str)-1] == '!')
						{
						strcat(str,"*");
						SendDlgItemMessage(hwnd,10,WM_SETTEXT,0,(long)str);		
						}
					}
				break;

				case '/':
					if(HIWORD(wParam) == BN_CLICKED)
					{
					char str[256]="";
					c=0;
					SendDlgItemMessage(hwnd,10,WM_GETTEXT,sizeof(str),(long)str);		
						if(str[strlen(str)-1]=='+' ||str[strlen(str)-1]=='-' ||str[strlen(str)-1]=='*' ||str[strlen(str)-1]=='/'||str[strlen(str)-1]=='^')
						str[strlen(str)-1]=0;					
						if(str[strlen(str)-1] != ':' && str[strlen(str)-1]>=48 &&str[strlen(str)-1]<= 57 || str[strlen(str)-1] == '!')
						{
						strcat(str,"/");
						SendDlgItemMessage(hwnd,10,WM_SETTEXT,0,(long)str);		
						}
					}
				break;

				case '!':					
					if(HIWORD(wParam) == BN_CLICKED)
					{
					char str[256]="";
					c=0;
					SendDlgItemMessage(hwnd,10,WM_GETTEXT,sizeof(str),(long)str);		
						if(str[strlen(str)-1]=='+' ||str[strlen(str)-1]=='-' ||str[strlen(str)-1]=='*' ||str[strlen(str)-1]=='/' ||str[strlen(str)-1]=='!' ||str[strlen(str)-1]=='^')
						str[strlen(str)-1]=0;					
						if(str[strlen(str)-1] != '!' && str[strlen(str)-1]>=48 &&str[strlen(str)-1]<= 57)
						{
						strcat(str,"!");
						SendDlgItemMessage(hwnd,10,WM_SETTEXT,0,(long)str);		
						}
					}
				break;


				case '^':			
					if(HIWORD(wParam) == BN_CLICKED)
					{
					char str[256]="";
					c=0;
					SendDlgItemMessage(hwnd,10,WM_GETTEXT,sizeof(str),(long)str);		
					
						if(str[strlen(str)-1]=='+' ||str[strlen(str)-1]=='-' ||str[strlen(str)-1]=='*' ||str[strlen(str)-1]=='/'||str[strlen(str)-1]=='^')
						str[strlen(str)-1]=0;					
					
						if(str[strlen(str)-1] != '^' && str[strlen(str)-1]>=48 &&str[strlen(str)-1]<= 57 || str[strlen(str)-1] == '!')
						{
						strcat(str,"^");
						SendDlgItemMessage(hwnd,10,WM_SETTEXT,0,(long)str);		
						}
					}
				break;

				case '=':			
					if(HIWORD(wParam) == BN_CLICKED)
					{
					static char str[400]="";
						if(c==0)
						{
						SendDlgItemMessage(hwnd,10,WM_GETTEXT,sizeof(str),(long)str);
						infix_to_postfix(str);
						SendDlgItemMessage(hwnd,10,WM_SETTEXT,0,(long)str);
						c=1;
						}
						else if(c==1)
						{
						postfix_calculation(str);
						SendDlgItemMessage(hwnd,10,WM_SETTEXT,0,(long)str);
						memset(str,0,sizeof(str));
						c=2;
						}
						else if(c==2)
						{
						SendDlgItemMessage(hwnd,10,WM_SETTEXT,0,(long)str);
						c=0;
						}
					break;
					
					}
				break;
			
				case '.':			
					if(HIWORD(wParam) == BN_CLICKED)
					{
					char str[256]="";
					c=0;
					SendDlgItemMessage(hwnd,10,WM_GETTEXT,sizeof(str),(long)str);		
						if(str[strlen(str)-1]=='+' ||str[strlen(str)-1]=='-' ||str[strlen(str)-1]=='*' ||str[strlen(str)-1]=='/' ||str[strlen(str)-1]=='^')
						str[strlen(str)-1]=0;					
				
						if(str[strlen(str)-1] != '.' && str[strlen(str)-1]>=48 &&str[strlen(str)-1]<= 57)
						{
						strcat(str,".");
						SendDlgItemMessage(hwnd,10,WM_SETTEXT,0,(long)str);		
						}
					}
				break;

				case 0:			
					if(HIWORD(wParam) == BN_CLICKED)
					{
					char str[256]="";
					SendDlgItemMessage(hwnd,10,WM_GETTEXT,sizeof(str),(long)str);		
						if(str[strlen(str)-1]!=0  && str[strlen(str)-1] != '!' )
						{
						strcat(str,"0");
						SendDlgItemMessage(hwnd,10,WM_SETTEXT,0,(long)str);		
						}
					}
				break;
				
				case 1:					
					if(HIWORD(wParam) == BN_CLICKED)
					{
					char str[256]="";
					SendDlgItemMessage(hwnd,10,WM_GETTEXT,sizeof(str),(long)str);		
						if(str[strlen(str)-1] != '!') 
						{
						strcat(str,"1");
						SendDlgItemMessage(hwnd,10,WM_SETTEXT,0,(long)str);		
						}
					}
				break;

				case 2:					
					if(HIWORD(wParam) == BN_CLICKED)
					{
					char str[256]="";
					SendDlgItemMessage(hwnd,10,WM_GETTEXT,sizeof(str),(long)str);		
						if(str[strlen(str)-1] != '!') 
						{
						strcat(str,"2");
						SendDlgItemMessage(hwnd,10,WM_SETTEXT,0,(long)str);		
						}
					}
				break;
				
				case 3:					
					if(HIWORD(wParam) == BN_CLICKED)
					{
					char str[256]="";
					SendDlgItemMessage(hwnd,10,WM_GETTEXT,sizeof(str),(long)str);		
						if(str[strlen(str)-1] != '!') 
						{						
						strcat(str,"3");
						SendDlgItemMessage(hwnd,10,WM_SETTEXT,0,(long)str);		
						}
					}
				break;
				
				case 4:					
					if(HIWORD(wParam) == BN_CLICKED)
					{
					char str[256]="";
					SendDlgItemMessage(hwnd,10,WM_GETTEXT,sizeof(str),(long)str);		
						if(str[strlen(str)-1] != '!') 
						{						
						strcat(str,"4");
						SendDlgItemMessage(hwnd,10,WM_SETTEXT,0,(long)str);		
						}
					}
				break;
				
				case 5:			
					if(HIWORD(wParam) == BN_CLICKED)
					{
					char str[256]="";
					SendDlgItemMessage(hwnd,10,WM_GETTEXT,sizeof(str),(long)str);		
						if(str[strlen(str)-1] != '!') 
						{						
						strcat(str,"5");
						SendDlgItemMessage(hwnd,10,WM_SETTEXT,0,(long)str);		
						}
					}
				break;
				
				case 6:
					if(HIWORD(wParam) == BN_CLICKED)
					{
					char str[256]="";
					SendDlgItemMessage(hwnd,10,WM_GETTEXT,sizeof(str),(long)str);		
						if(str[strlen(str)-1] != '!') 
						{						
						strcat(str,"6");
						SendDlgItemMessage(hwnd,10,WM_SETTEXT,0,(long)str);		
						}
					}
				break;

				case 7:					
					if(HIWORD(wParam) == BN_CLICKED)
					{
					char str[256]="";
					SendDlgItemMessage(hwnd,10,WM_GETTEXT,sizeof(str),(long)str);		
						if(str[strlen(str)-1] != '!') 
						{						
						strcat(str,"7");
						SendDlgItemMessage(hwnd,10,WM_SETTEXT,0,(long)str);		
						}
					}
				break;
				
				case 8:					
					if(HIWORD(wParam) == BN_CLICKED)
					{
					char str[256]="";
					SendDlgItemMessage(hwnd,10,WM_GETTEXT,sizeof(str),(long)str);		
						if(str[strlen(str)-1] != '!') 
						{						
						strcat(str,"8");
						SendDlgItemMessage(hwnd,10,WM_SETTEXT,0,(long)str);		
						}
					}
				break;
				
				case 9:					
					if(HIWORD(wParam) == BN_CLICKED)
					{
					char str[256]="";
					SendDlgItemMessage(hwnd,10,WM_GETTEXT,sizeof(str),(long)str);		
						if(str[strlen(str)-1] != '!') 
						{						
						strcat(str,"9");
						SendDlgItemMessage(hwnd,10,WM_SETTEXT,0,(long)str);		
						}
					}
				break;

				case 'C':					
					if(HIWORD(wParam) == BN_CLICKED)
					{
					char str[256]="";
					c=0;
					SendDlgItemMessage(hwnd,10,WM_SETTEXT,0,(long)str);		
					}
				break;

				case 'D':					
					if(HIWORD(wParam) == BN_CLICKED)
					{
					char str[400]="";
					char str1[400]="";
					
					SendDlgItemMessage(hwnd,10,WM_GETTEXT,sizeof(str1),(long)str1);	
					if(str1[0]>0 && str1[0]<255) //Field is not empty
					memcpy(str,str1, strlen(str1)-1);
					SendDlgItemMessage(hwnd,10,WM_SETTEXT,sizeof(str),(long)str);		
					}
				break;

				case 30:
					if(HIWORD(wParam) == BN_CLICKED)
					exit(1);
				break;

				case 50:
					if(HIWORD(wParam) == BN_DBLCLK)
					{
					char str[255]="";
					SendDlgItemMessage(hwnd,10,WM_GETTEXT,sizeof(str),(long)str);	
						MessageBox(hwnd,"BN_DBLCLK","Notification or Event",0);
					}
						break;	
			}
		break;

		default:
		break;
	}
return	DefWindowProc(hwnd,message,wParam,lParam);
}