#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv)
{
	FILE* fp;
	float percentage;
	long int period = 100L;
	char LED = 0;
	char *str;
	char sval1,sval2,sval3,sval4;
	size_t num_of_bytes = 6;
	bool op=1;
	//char *str_but;
	char tval1,temp;
	if(argc == 2)
	{
		sscanf(argv[1],"%f",&percentage);
	}
	else
	{
		printf("Pogresan broj argumenata\n");
		return -1;
	}

	while(1) 
	{
		// Upali diode
		fp = fopen("/dev/led", "w");
		if(fp == NULL)
		{
			printf("Problem pri otvaranju /dev/led\n");
			return -1;
		}
		fprintf(fp, "%c", LED);
		if(fclose(fp))
		{
			printf("Problem pri zatvaranju /dev/led\n");
			return -1;
		}
		usleep(percentage*period);

		fp = fopen ("/dev/switch", "r");
		if(fp==NULL)
		{
			puts("Problem pri otvaranju /dev/switch");
			return -1;
		}


		str = (char *)malloc(num_of_bytes+1); 
		getline(&str, &num_of_bytes, fp); 

		if(fclose(fp))
		{
			puts("Problem pri zatvaranju /dev/switch");
			return -1;
		}


		sval1 = str[2] - 48;
		sval2 = str[3] - 48;
		sval3 = str[4] - 48;
		sval4 = str[5] - 48;

		free(str);

		fp = fopen ("/dev/button", "r");
		if(fp==NULL)
		{
			puts("Problem pri otvaranju /dev/button");
			return -1;
		}


		str = (char *)malloc(num_of_bytes+1); 
		getline(&str, &num_of_bytes, fp); 

		if(fclose(fp))
		{
			puts("Problem pri zatvaranju /dev/button");
			return -1;
		}


		tval1 = str[2] - 48;
		temp = tva1l;
		usleep (period);
		if(tval1 == temp)
			op~=op;

		free(str);
		
		if(sval4 == '1')
			if(op == 1)
				LED = LED + sval1 + 2*sval2 + 4*sval3;
			else
				LED = LED - sval1 - 2*sval2 - 4*sval3;
	

		fprintf(fp, "%c\n", LED);
		if(fclose(fp))
		{
			printf("Problem pri zatvaranju /dev/led\n");
			return -1;
		}



		
		


		
		
		
	}
	return 0;
}

