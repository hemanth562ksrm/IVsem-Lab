#include<stdio.h>
#include<string.h>

void main()
{
    int i = 0, j = 0, n, pos;
    char a[20], b[100], ch;

    printf("Enter the string:\n");
    scanf("%s", a);

    n = strlen(a);

    printf("Enter position to insert the character:\n");
    scanf("%d", &pos);

    // Validate position
    while(pos < 1 || pos > n + 1)
    {
        printf("Invalid position, enter again: ");
        scanf("%d", &pos);
    }

    getchar(); // Clear newline left by previous scanf
    printf("Enter the character to stuff:\n");
    ch = getchar();

    // Add starting frame delimiter
    b[0] = 'd'; b[1] = 'l'; b[2] = 'e'; b[3] = 's'; b[4] = 't'; b[5] = 'x';
    j = 6;

    for (i = 0; i < n; i++)
    {
        // Insert stuffing character at given position
        if (i == pos - 1)
        {
            b[j++] = 'd'; b[j++] = 'l'; b[j++] = 'e';
            b[j++] = ch;
            b[j++] = 'd'; b[j++] = 'l'; b[j++] = 'e';
        }

        // Escape 'dle' sequence
        if (a[i] == 'd' && a[i + 1] == 'l' && a[i + 2] == 'e')
        {
            b[j++] = 'd'; b[j++] = 'l'; b[j++] = 'e';
        }

        b[j++] = a[i];
    }

    // If position is at the end
    if (pos == n + 1)
    {
        b[j++] = 'd'; b[j++] = 'l'; b[j++] = 'e';
        b[j++] = ch;
        b[j++] = 'd'; b[j++] = 'l'; b[j++] = 'e';
    }

    // Add ending frame delimiter
    b[j++] = 'd'; b[j++] = 'l'; b[j++] = 'e'; b[j++] = 'e'; b[j++] = 't'; b[j++] = 'x';
    b[j] = '\0';

    printf("\nFrame after stuffing:\n%s\n", b);
}