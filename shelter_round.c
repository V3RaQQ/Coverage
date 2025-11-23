#include <stdio.h>
#include <string.h>

int is_white(const char c);
void change_whites(char str[]);
int guess_eval(const int guess, const int my_number);
int leap_year(const int year);
int count_positives(const int size, const int array[]);
int count_whites(const char string[]);
int direction_correction(const int degree);
int all_positives(const int size, const int array[]);
int last_positive(const int size, const int array[]);
int binary_num(const int num);


int main() {
    printf("%d %d\n", is_white('#'), is_white(' '));

    char test[] = "Hello world\nNew line";
    change_whites(test);
    printf("%s\n", test);
    printf("%d %d %d\n", guess_eval(5, 5), guess_eval(3, 5), guess_eval(7, 5));
    printf("%d %d %d %d %d\n", leap_year(2000), leap_year(1900), leap_year(2004), leap_year(2001), leap_year(5000));
    int arr[] = {1, -2, 3, 4, -5};
    printf("%d\n", count_positives(5, arr)); 

    printf("%d %d %d\n", 
           direction_correction(-90), 
           direction_correction(540), 
           direction_correction(180));

    int arr2[] = {1, 2, 3, 4, 5};
    int arr3[] = {1, -2, 3, 4, 5};
    printf("%d %d\n", all_positives(5, arr2), all_positives(5, arr3));
    int arr4[] = {-1, -2, 3, -4, 5};
    printf("%d\n", last_positive(5, arr4));
    printf("%d %d %d\n", binary_num(0), binary_num(1), binary_num(2));
    

    return 0;
}

int is_white(const char c)
{
    int flag = 0;

    if (c == ' ')
        flag = 1;

    if (c == '\t')
        flag = 1;

    if (c == '\n')
        flag = 1;

    return flag;
}

void change_whites(char string[])
{
    if (!string)
        return;

    int pos = 0;
    char current;

    while (1)
    {
        current = string[pos];

        if (current == '\0')
            break;

        if (current == ' ' || current == '\n')
        {
            string[pos] = '.';
        }

        pos++;
    }
}

int guess_eval(const int guess, const int my_number)
{
    if (guess == my_number) {
        return 1;   
    }
    else if (my_number > guess) {
        return 2;     
    }
    else {
        return 0;    
    }
}

int leap_year(const int year)
{
    if (year < 1 || year > 4443) {
        return -1;
    }

    if (year % 400 == 0) {
        return 1;
    }
    if (year % 100 == 0) {
        return 0;
    }
    if (year % 4 == 0) {
        return 1;
    }

    return 0;
}

int count_positives(const int size, const int array[]) {
    if (array == NULL) {
        return -1;
    }

    int count = 0;
    
    for (int i = 0; i < size; i++) {
        if (array[i] > 0) {
            count++;
        }
    }

    return count;
}

int count_whites(const char string[]) {
    if (string == NULL) {
        return -1;
    }

    int count = 0;
    int len = strlen(string);
    
    for (int i = 0; i < len; i++) {
        count += (string[i] == ' ' || string[i] == '\n' || string[i] == '\t');
    }
    
    return count;
}

int direction_correction(const int degree) {
    if (degree < 0 && degree % 90 != 0) {
        return -1;
    }
    
    if (degree < 0) {
        return -1;
    }
    
    if (degree % 90 != 0) {
        return -1;
    }

    int corrected_degree = degree % 360;

    return corrected_degree;
}

int all_positives(const int size, const int array[]) {
    for (int i = 0; i < size; i++) {
        if (array[i] <= 0) {
            return 0;
        }
    }

    return 1;
}

int last_positive(const int size, const int array[]) {
    int last_val = -1; 
    
    for (int i = 0; i < size; i++) {
        last_val = (array[i] > 0) ? array[i] : last_val;
    }

    return last_val;
}

int binary_num(const int num) {
    if (num <= -1000 || num >= 1000) {
        return -1;
    }

    if (num == 0 || num == 1) {
        return 1;
    }

    return 0;
}

void swap_sign(const int size, int array[]) {
    for (int i = 0; i < size; i++) {
        array[i] = array[i] * -1;
    }
}

int div_by_3(const int num) {
  return num % 3 == 0;
}

int same_case(const char a, const char b) {
  return isalpha(a) && isalpha(b) ? (islower(a) && islower(b)) || (isupper(a) && isupper(b)) : -1;
}

int find_first_A(const char string[]) {
  if (string == NULL) return -1;
  for (int i = 0; i < strlen(string); i++) 
    if (string[i] == 'A' || string[i] == 'a') 
      return i;
  return -1;
}

void string_to_upper(char string[]) {
  for (int i = 0; i < strlen(string); i++) 
    string[i] = toupper(string[i]);
}
