#include "histogram.h"

#include <math.h>
#include <iostream>
#include <conio.h>
#include <vector>
using namespace std;



vector<double> input_numbers(istream& in, size_t cnt) {
    vector<double> result(cnt);
    for (size_t i = 0; i < cnt; i++)

    for (double number : numbers)
    {
        in >> result[i];
    }
    return result;
}

void
show_histogram_text(vector<size_t> bins) //âûâîä ãèñòîãðàìû çâåçäî÷êàìè
{
    const size_t SCREEN_WIDTH = 80;
    const size_t MAX_ASTERISK = SCREEN_WIDTH - 3 - 1;
    size_t max_bin = bins[0];
    for (double bin : bins)
    {
        if (bin > max_bin)
        {
            max_bin = bin;
        }
    }
    for (double bin : bins)
    {
        size_t height = bin;
        // ïðîâåðèòü ìàñøòàáèðîâàíèå(ïåðåñ÷èòàòü height)

        if (max_bin > MAX_ASTERISK)
        {
            height = MAX_ASTERISK * (static_cast<double> (bin) / max_bin);
        }


        if (bin < 100) {
            cout << " ";
        }

        if (bin < 10) {
            cout << " ";
        }
        cout << bin << "|";
        for (size_t i = 0; i < height; i++)
        {
            cout << "*";
        }
        cout << endl;
    }
}



int main(istream& in)
{
    //ââîä äàííûõ

    size_t number_count;
    cerr << "Enter number count: ";

    cin >> number_count;
    cerr << "Enter numbers: ";

    const auto numbers = input_numbers(in , number_count);

    size_t bin_count;
    cerr << "Enter bin count: ";
    cin >> bin_count;

    //ðàñ÷åò äàííûõ

    const auto bins = make_histogram(numbers, bin_count);

    //âûâîä ãèñòðîãðàìû

    show_histogram_svg(bins);

    return 0;
}
