#include <stdio.h>
/*实现命令行参数的逆波兰表达式的程序*/
#define INTBUF 10	//数值缓存数组长度
int buf[INTBUF];
int ChartoInt(char *ch);
main(int argc, char **argv)
{
	int i,k,l=0;
	for(i = 1; i < argc; i++)
		{
			if(**(argv+i) > 48){
				k = ChartoInt(*(argv+i));
				buf[l] = k;
				l++;
			}else{
				switch(**(argv+i))
				{
				case 43:	//43为‘+’
					buf[l-2] += buf[l-1];
					l--;
					break;
				case 45:	//45为 ‘-’
					buf[l-2] -= buf[l-1];
					l--;
					break;
				case 42 :	//42为 ‘*’
					buf[l-2] *= buf[l-1];
					l--;
					break;
				case 47:	//47为 ‘/’
					buf[l-2] /= buf[l-1];
					l--;
					break;
				default:
					;
					break;
				}
			}
		}
	printf("%d",buf[0]);
}
int ChartoInt(char *ch)
{
	int tmp = 0,i = 0;
	while(*(ch+i))
	{
		tmp = tmp * 10 + (*(ch+i) - '0');
		i++;
	}
	return tmp;
}