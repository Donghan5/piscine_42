#include <unistd.h>

void	print_bits(unsigned char octet)
{
	unsigned char	binary;
	int	i;

	i = 8;
	binary = 0;
	while (i > 0)
	{
		binary = binary * 2 + (octet % 2);
		octet /= 2;
		write(1, &binary, 1);
		i--;
	}
}

int main(void)
{
	print_bits(0);
	write(1, "\n", 1);
	print_bits(1);
	write(1, "\n", 1);
	print_bits(2);
	write(1, "\n", 1);
	print_bits(10);
	write(1, "\n", 1);
	print_bits(113);
	write(1, "\n", 1);
	print_bits(255);
	write(1, "\n", 1);
	return (0);
}

