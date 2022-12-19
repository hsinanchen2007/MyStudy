- 倒推法：
    - 长度为1:true
    - 长度大于2: 从到处第二位依次往前遍历
        - 如果值为0: 且位置为奇数，则返回false；为偶数的返回true（这里的位置指的是从后往前数，是第几个数字，从1开始）
        - 如果值为1: 
            - 如果遍历到第一个数字了，数组长度是偶数返回false，奇数返回true
            - 否则继续向前遍历
    // 找规律（0是数组的最后一位）
    // 0 true
    // 0 0 true
    // 0 1 如果1是独立的，就是false
    // 0 1 0 false
    // 0 1 1 如果1是独立的，就是true
    // 0 1 1 0 true
    // 0 1 1 1 如果1是独立的，就是false
    // 0 1 1 1 0 false
    // 0 1 1 1 1 如果1是独立的，就是true
    // 代码如下
    
```
    int length = bits.length;
    if (length==1) {
        return true;
    } else {
        int index = length - 2;
        while (index>=0) {
            int val = bits[index];
            if (val==0) {
                if((length-index)%2==0) {
                    return true;
                } else {
                    return false;
                }
            } else if(index==0) {
                if (length%2==0) {
                    return false;
                } else {
                    return true;
                }
            }
            index--;
        }
    }
     return false;
```

- 正推法（比较好理解，这个思路是参考其他童鞋的）
    从数组第一位开始遍历，i=0，循环终止条件（i<lengtn-1）
        如果值为1，则肯定是二比特，i=i+2
        如果值为1，则肯定是一比特（因为0开头的肯定是一比特），i++
    为啥是lengtn-1，就是想看倒数第二个数字是一比特还是二比特，如果是一比特，i=length-1；但如果是二比特，在经历i=i+2之后，i应该是等于index
    // 代码如下
    
```
    int length = bits.length;
    int i = 0;
    while (i<length-1) {
        if (bits[i] == 0) {
            i++;
        } else {
            i = i+2;
        }
    }
    if (i!=length) {
        return true;
    } else {
        return false;
    }
```

    