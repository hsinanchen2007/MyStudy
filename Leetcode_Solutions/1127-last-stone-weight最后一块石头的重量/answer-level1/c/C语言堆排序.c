void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void shiftDown(int *array, int i, int length)
{
	int child;
	while (2 * i + 1 < length) {
		child = 2 * i + 1;
		if (child + 1 < length && array[child] > array[child + 1]) {
			child++;
		}
		if (array[i] > array[child]) {
			swap(&array[i], &array[child]);
		} else {
			break;
		}
		i = child;
	}
}

void heapSort(int *array, int length)
{
	int i;
	
	if (length <= 1) {
		return;
	}
	
	for (i = length / 2 - 1; i >= 0; i--) {
		shiftDown(array, i, length);
	}
	
	for (i = length - 1; i >= 0; i--) {
		swap(&array[0], &array[i]);
		shiftDown(array, 0, i);
	}
}

int lastStoneWeight(int* stones, int stonesSize){
    int temp[2];
    int size;

    size = stonesSize;
    while (size > 1) {
        heapSort(stones, size);
        temp[0] = stones[0];
        temp[1] = stones[1];

        if (temp[0] == temp[1]) {
            stones = stones + 2;
            size -= 2;
        } else {
            stones[1] = temp[0] - temp[1];
            stones += 1;
            size -= 1;
        }
    }

    if (size == 0) {
        return 0;
    } else {
        return stones[0];
    }
}