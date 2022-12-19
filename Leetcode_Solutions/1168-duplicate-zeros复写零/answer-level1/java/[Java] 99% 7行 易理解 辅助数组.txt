- ****解题思路**：**
- 照着原数组来遍历
```
public void duplicateZeros(int[] arr) {
        int[] temp = Arrays.copyOf(arr, arr.length);//复制原数组到temp
        int index = 0;//指向temp的数组下标
        for(int i = 0; i < arr.length; i++){//修改原数组（只要把原数组修改完就行，temp数组可能未遍历完）
            arr[i] = temp[index];//将temp[index]的值直接给arr[i]
            if(temp[index++] == 0 && i+1 < arr.length){//如果temp[index]==0的话，考虑补0
                arr[i+1] = 0;
                i++;
            }
        } 
    }
```
