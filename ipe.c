#include <stdio.h>
/*ʵ�������в������沨�����ʽ�ĳ���*/
#define INTBUF 10	//��ֵ�������鳤��
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
				case 43:	//43Ϊ��+��
					buf[l-2] += buf[l-1];
					l--;
					break;
				case 45:	//45Ϊ ��-��
					buf[l-2] -= buf[l-1];
					l--;
					break;
				case 42 :	//42Ϊ ��*��
					buf[l-2] *= buf[l-1];
					l--;
					break;
				case 47:	//47Ϊ ��/��
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