#include <iostream>

void	toUpper(char **str)
{
	int	i;

	i = 0;
	while ((*str)[i])
	{
		if ((*str)[i] >= 'a' && (*str)[i] <= 'z')
			(*str)[i] -= 32;
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		i = 1;
		while (argv[i])
		{
			toUpper(&argv[i]);
			std::cout << argv[i];
			i++;
		}
		std::cout << std::endl;
	}
	return (0);
}
