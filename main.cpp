#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;
vector<unsigned> amicable_numbers;

unsigned SumOfFactors(unsigned x)
{
    unsigned sum = 1;
    if (x != 1)
    {
        unsigned root = sqrt(x);

        if (x % 2 == 0)
        {
            for (unsigned i = 2;  i <= root;  ++i)
                if (x % i == 0)
                    sum += i + x/i;
        }
        else
        {
            for (unsigned i = 3;  i <= root;  i += 2)
                if (x % i == 0)
                    sum += i + x/i;
        }

        if (root * root == x)
        {
            sum -= root;
        }
    }

    return sum;
}

bool MeetsConditions(unsigned k)
{
    int sum = SumOfFactors(k);

    if (k != sum)
    {
        for (unsigned i = 0;  i < amicable_numbers.size();  ++i)
            if (k == amicable_numbers[i] || sum == amicable_numbers[i])
                return false;

        if (k == SumOfFactors(sum))
        {
            amicable_numbers.push_back(k);
            return true;
        }
    }
    return false;
}

int main()
{
    unsigned n, i = 1;
    cout << "n = "; cin >> n; cout << "--------\n";
    for (unsigned k = 1;  i <= n;  ++k)
    {
        if (MeetsConditions(k))
        {
            cout << k << ", " << SumOfFactors(k) << endl;
            ++i;
        }
    }
    cout << "\n";
    system("pause");

    return 0;
}
