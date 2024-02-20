#include <stdio.h>
#include <stdlib.h>
#define null NULL
int* bubble_sort(int* l, int n) {

    for (int i = 0; i < n ; i++){
        for (int j = 0; j < n-i-1; j++){
            if (l[j] > l[j+1]) {
                int temp = l[j];
                l[j] = l[j+1];
                l[j+1] = temp;
            }
        }
    }
    return l;
} 
int* selection_sort(int* l, int n) {
    for (int i = 0; i < n; i++){
        int min_index = i;
        for (int j = i + 1; j < n; j++){
            if (l[j] < l[min_index]){
                min_index = j;
        }
        }
    int temp = l[i];
    l[i] = l[min_index];
    l[min_index] = temp;
    }
    return l;
}
int* insertion_sort(int* l, int list_length) {
    for (int i = 1; i < list_length; i++) {
        int key = l[i];
        int j = i-1;
        while(j >= 0 && key < l[j]) {
            l[j+1] = l[j];
            j--;
            l[j+1] = key;
        }
    }
    return l;
}
int* quick_sort(int* l, int list_length) {
    if(list_length <= 1) {
        return l;
    }

    int pivot = l[0];
    int *left = (int *)malloc(list_length * sizeof(int));
    int *right = (int *)malloc(list_length * sizeof(int));
    int *mid = (int *)malloc(list_length * sizeof(int));

    if (left == NULL || right == NULL || mid == NULL) {
        printf("Memory allocation failed");
        return NULL;
    }

    int mid_index = 0, left_index = 0, right_index = 0;
    for (int i = 0; i < list_length; i++) {
        if (l[i] < pivot) {
            left[left_index] = l[i];
            left_index++;
        } else if (l[i] > pivot) {
            right[right_index] = l[i];
            right_index++;
        } else {
            mid[mid_index] = l[i];
            mid_index++;
        }
    }

    int* sorted_left = quick_sort(left, left_index);
    int* sorted_right = quick_sort(right, right_index);

    for (int i = 0; i < left_index; i++) {
        l[i] = sorted_left[i];
    }
    for (int i = 0; i < mid_index; i++) {
        l[left_index + i] = mid[i];
    }
    for (int i = 0; i < right_index; i++) {
        l[left_index + mid_index + i] = sorted_right[i];
    }

    free(left);
    free(right);
    free(mid);

    return l;
}

int main() {
    int list1[] = {5, 6, 7, 3, 7, 8};
    int list2[] = {1, 0, 3, 4, 8, 9};
    int list3[] = {5, 6, 4, 2, 3, 7};
    int list4[] = {6, 5, 7, 2, 4, 6};
    int* sorted_l1 = bubble_sort(list1, 6);
    int* sorted_l2 = selection_sort(list2, 6);
    int* sorted_l3 = insertion_sort(list3, 6);
    int* sorted_l4 = quick_sort(list4, 6);
    printf("Sorted list1 : \n");
    for (int i=0; i<6; i++) {
        printf("%d ", sorted_l1[i]);
    }
    printf("\n");
    printf("Sorted list2 : \n");
    for (int i=0; i<6; i++) {
        printf("%d ", sorted_l2[i]);
    }
    printf("\n");
    printf("Sorted list3 : \n");
    for (int i=0; i<6; i++) {
        printf("%d ", sorted_l3[i]);
    }
    printf("\n");
    printf("Sorted list4 : \n");
    for (int i=0; i<6; i++) {
        printf("%d ", sorted_l4[i]);
    }
    printf("\n");
   
   

    return 0;
}
