#include <iostream>
#include <locale>
#include <iomanip>
#include <iterator>

#include <Windows.h> 

int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	const double currate = 87.69;
	
	std::locale locale_in("deu_deu.utf8");
	std::locale locale_out("ru_RU.utf8");
	long double amt = 0.0;
	std::cin.imbue(locale_in);
	while (std::cin >> std::get_money(amt, true))
	{
		std::cout.imbue(locale_in);
		std::cout << std::showbase << std::put_money(amt) << " <> ";
		amt *= currate;
		std::cout.imbue(locale_out);
		std::cout << std::showbase << std::put_money(amt) << '\n';
	}
	
	return 0;
}