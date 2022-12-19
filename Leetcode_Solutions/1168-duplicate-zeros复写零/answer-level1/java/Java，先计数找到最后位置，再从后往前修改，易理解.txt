先一次遍历，利用count计数，遍历到0，count+2，否则+1，最后count的结果要么为数组长度，要么比数组长度多1（最后元素为0且不应复写），last为找到最后保留数的位置。
```
public void duplicateZeros(int[] arr) {
        int last = 0, count = 0;// count记录复写0后的元素个数
        // 找到最后一个保留数的位置
        while (last < arr.length) {
            count += arr[last] == 0 ? 2 : 1;
            if (count >= arr.length) {
                break;
            }
            last++;
        }
        // 此时count可能为arr.length或arr.length + 1
        count--;// 减1，若为arr.length，则说明最后一个保留数值为0，且该0不应该复写
        if (count == arr.length) {
            count--;
            arr[count--] = arr[last--];
        }
        // 从后往前修改
        while (count >= 0) {
            if (arr[last] == 0) {
                arr[count--] = 0;
            }
            arr[count--] = arr[last--];
        }
    }
```
