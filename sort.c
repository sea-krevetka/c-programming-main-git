void stalin_sort(int* numbers, int* size) {
    int i = 0;
    int maximal = numbers[0];
    int* gulag = (int*)malloc(*size * sizeof(int)); //creating array
    int gulag_size = 0;

    while (i < *size) {
        int element = numbers[i];
        if (maximal > element) {
            printf("Element %d sent to Gulag\n", element);
            gulag[gulag_size++] = element;
            for (int j = i; j < *size - 1; j++) {
                numbers[j] = numbers[j + 1];
            }
            (*size)--;
        } else {
            maximal = element;
            i++;
        }
    }

    printf("Numbers: ");
    for (i = 0; i < *size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n"); //yay its a comment!!

    printf("Gulag: ");
    for (i = 0; i < gulag_size; i++) {
        printf("%d ", gulag[i]);
    }
    printf("\n");

    free(gulag);
}