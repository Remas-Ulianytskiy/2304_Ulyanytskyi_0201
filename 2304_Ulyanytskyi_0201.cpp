#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int get_user_input()
{
    int value;
    cin >> value;
    return value;
}

void fill_vector(vector<int>& A, int vector_size)
{
    srand(time(0));
    A.clear();
    for (int i = 0; i < vector_size; ++i)
        A.push_back(rand() % 2001 - 1000);
}

void display_vector(vector<int>& A)
{
    cout << "{ ";
    for (int& element : A)
        cout << element << ' ';
    cout << '}';
}

vector<int> solution(vector<int>& A, int K)
{
    int a_size = A.size();
    vector<int> result(a_size);    

    for (int i = 0; i < a_size; ++i)
        result[(i + K) % a_size] = A[i];

    return result;
}

int main()
{
    int vector_size, shifts_amount;
    vector<int> original_vector, result_vector;

    while (true)
    {
        cout << "Enter vector size (0 - 100]: ";
        vector_size = get_user_input();
        cout << "Enter the number of shifts [0 - 200]: ";
        shifts_amount = get_user_input();

        bool check_vector_size = vector_size > 0 && vector_size <= 100;
        bool check_shifts_amount = shifts_amount >= 0 && shifts_amount <= 200;
        
        if (check_vector_size && check_shifts_amount)
        {
            fill_vector(original_vector, vector_size);
            result_vector = solution(original_vector, shifts_amount);
            cout << "Original vector: ";
            display_vector(original_vector);
            cout << "\nResult vector:   ";
            display_vector(result_vector);
        }
        else
        {
            cout << "Invalid input!";
        }

        cout << endl << endl;
    }

    return 0;
}