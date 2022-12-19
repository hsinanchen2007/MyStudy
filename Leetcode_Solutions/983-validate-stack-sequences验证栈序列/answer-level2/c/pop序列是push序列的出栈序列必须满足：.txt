**pop序列是push序列的出栈序列必须满足条件：**
    **遍历pop序列每个元素x对应的push索引xindex，以xindex为起点，后续所有小于xindex的值必须呈现降序排列。**
    举例：push序列[2,1,5,6,7]，pop序列[6,2,1,5,7] pop对应在push的index序列[3,0,1,2,4]
         那么index=3右侧所有小于3的数字呈现0、1、2升序排列，因此不满足条件。

		
        int getIndex(int num, int* arr, int arrSize){
			int i;
			for (i = 0; i < arrSize; i++) {
				if (arr[i] == num) {
					return i;
				}
			}
			return -1;
		}
		bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize){
			int i;
			if (pushedSize != poppedSize) {
				return false;
			}
		
			if (poppedSize == 0) {
				return true;
			}
		
			int indexPop[poppedSize];
			for (i = 0; i < pushedSize; i++) {
				indexPop[i] = getIndex(popped[i], pushed, pushedSize);
			}
			for (i = 0; i < poppedSize; i++) {
				int j;
				if (indexPop[i] == -1) {
					return false;
				}
				int minIndex = -1;   
				for (j = i; j < poppedSize; j++) {
					if (indexPop[j] < indexPop[i]) {
						if (indexPop[j] == -1) {
							return false;
						}
						if (minIndex != -1 && minIndex < indexPop[j]) {
							return false;
						} else {
							minIndex = indexPop[j];
						}
					}
				}
			}
		
			return true;
		}

