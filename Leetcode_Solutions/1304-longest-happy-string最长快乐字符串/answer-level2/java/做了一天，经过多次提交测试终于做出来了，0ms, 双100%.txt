### 解题思路
1. 首先计算a,b,c三个数的大小（假设a > b > c）;
```
//返回值为nums下标数组，其中下标0处为最大值，下标2处为最小值
    public int[] sort(int[] nums){
        int[] index = new int[3];
        int max = -1;
        int indexMax = -1;
        int min = 101;
        int indexMin = -1;
        for(int i = 0; i < 3; i ++){
            if(max < nums[i]){
                max = nums[i];
                indexMax = i;
            }
            if(min > nums[i]){
                min = nums[i];
                indexMin = i;
            }
        }
        if(max == min) {
        	for(int i = 0; i < 3; i ++) index[i] = i;
        	return index;
        }
        index[0] = indexMax;
        index[2] = indexMin;
        index[1] = 3 - indexMax - indexMin;
        return index;
    }
```

2. 而后通过计算a,b,c都减去c，得到的差值a - c,b -c, 0;
```
int leaving = nums[index[2]];
for(int i = 0; i < 3; i ++){
    nums[i] -= leaving;
}
```
3. 若a - c 和 b - c 都不为零，则开始对前面两个数进行快乐字符串插入，首先若a - c 大于 b - c，则插入"aa"和"b"，直到(a - c) == (b - c);否则直接根据a - c != 0，b - c == 0，则跳跃步骤5；若a - c 和 b - c 则跳跃到步骤7.
```
while(nums[index[1]] > 0 && nums[index[0]] > nums[index[1]]){
    nums[index[0]] = addChar(nums[index[0]], (char)(index[0] + 'a'), result, 2);
    nums[index[1]] = addChar(nums[index[1]], (char)(index[1] + 'a'), result, 1);
}
```
4. 而后再插入"a"和"b",直到 a - c 等于0，也是b - c 等于0，因为(a - c) == (b - c)
```
while(nums[index[1]] > 0){
    nums[index[0]] = addChar(nums[index[0]], (char)(index[0] + 'a'), result, 1);
    nums[index[1]] = addChar(nums[index[1]], (char)(index[1] + 'a'), result, 1);
}
```
5. 若b - c等于0，而a - c不为零，此时b 和 c的值相同，我们则主要对a进行插入操作，首先若b > 0 && a - b > 2（这里隐含b 等于c），则进行如下插入，即先插入"aa"和"b"，再插入"aa"和"c"，直到b == 0或者 a - b <= 2;
```
while(nums[index[1]] > 0 && nums[index[0]] - nums[index[1]] > 2){
    nums[index[0]] = addChar(nums[index[0]], (char)(index[0] + 'a'), result, 2);
    nums[index[1]] = addChar(nums[index[1]], (char)(index[1] + 'a'), result, 1);
    nums[index[0]] = addChar(nums[index[0]], (char)(index[0] + 'a'), result, 2);
    nums[index[2]] = addChar(nums[index[2]], (char)(index[2] + 'a'), result, 1);
}
```
6. 若b == 0，则表明此时只剩下a，因为c等于b，此时若a >= 2,则插入"aa"，否则插入"a"（假设这里a > b）;若 a - b <= 2,则执行如下操作，若a - b == 2,则先插入"aa"和"b"，再插入"a"和"c",若a - b == 1,先插入"a"和"b"，再插入"a"和"c"
```
if(nums[index[1]] == 0){
    nums[index[0]] = addChar(nums[index[0]], (char)(index[0] + 'a'), result, Math.min(nums[index[0]], 2));
}else {
    nums[index[0]] = addChar(nums[index[0]], (char)(index[0] + 'a'), result, 
        Math.min(nums[index[0]] - nums[index[1]], 2));
    nums[index[1]] = addChar(nums[index[1]], (char)(index[1] + 'a'), result, 1);
    nums[index[0]] = addChar(nums[index[0]], (char)(index[0] + 'a'), result, 1);
    nums[index[2]] = addChar(nums[index[2]], (char)(index[2] + 'a'), result, 1);
}
```
7. 最后a，b，c相同，则依次插入"aa"、"bb"和"cc"，若最后各剩下1，则插入"a"、"b"和"c"
```
int diff = Math.min(nums[index[0]], 2);
while(true){
    nums[index[0]] = addChar(nums[index[0]], (char)(index[0] + 'a'), result, diff);
    nums[index[1]] = addChar(nums[index[1]], (char)(index[1] + 'a'), result, diff);
    nums[index[2]] = addChar(nums[index[2]], (char)(index[2] + 'a'), result, diff);
    diff = Math.min(nums[index[0]], 2);
    if(diff == 0) break;
}
```

方法addChar为拼接方法。
```
public int addChar(int num, char c, StringBuilder result, int diff){
    num -= diff;
    while(diff > 0){
        result.append(c);
        diff --;
    }
    return num;
}
```


### 代码

```java
class Solution {
    public String longestDiverseString(int a, int b, int c) {
        int[] nums = new int[3];
        nums[0] = a;
        nums[1] = b;
        nums[2] = c;
        StringBuilder result = new StringBuilder();
        int[] index = sort(nums);
        int leaving = nums[index[2]];
        for(int i = 0; i < 3; i ++){
            nums[i] -= leaving;
        }
        int count = 0;
        for(int i : nums){
            if(i == 0) count ++;
        }
        if(count == 1){
            while(nums[index[1]] > 0 && nums[index[0]] > nums[index[1]]){
                nums[index[0]] = addChar(nums[index[0]], (char)(index[0] + 'a'), result, 2);
                nums[index[1]] = addChar(nums[index[1]], (char)(index[1] + 'a'), result, 1);
            }
            while(nums[index[1]] > 0){
                nums[index[0]] = addChar(nums[index[0]], (char)(index[0] + 'a'), result, 1);
                nums[index[1]] = addChar(nums[index[1]], (char)(index[1] + 'a'), result, 1);
            }
            count ++;
            if(nums[index[0]] == 0) count ++;
        }
        nums[index[0]] += leaving;
        nums[index[1]] += leaving;
        nums[index[2]] += leaving;
        if(count == 2){
            while(nums[index[1]] > 0 && nums[index[0]] - nums[index[1]] > 2){
                nums[index[0]] = addChar(nums[index[0]], (char)(index[0] + 'a'), result, 2);
                nums[index[1]] = addChar(nums[index[1]], (char)(index[1] + 'a'), result, 1);
                nums[index[0]] = addChar(nums[index[0]], (char)(index[0] + 'a'), result, 2);
                nums[index[2]] = addChar(nums[index[2]], (char)(index[2] + 'a'), result, 1);
            }
            if(nums[index[1]] == 0){
                nums[index[0]] = addChar(nums[index[0]], (char)(index[0] + 'a'), result, Math.min(nums[index[0]], 2));
            }else {
            	nums[index[0]] = addChar(nums[index[0]], (char)(index[0] + 'a'), result, 
            			Math.min(nums[index[0]] - nums[index[1]], 2));
                nums[index[1]] = addChar(nums[index[1]], (char)(index[1] + 'a'), result, 1);
                nums[index[0]] = addChar(nums[index[0]], (char)(index[0] + 'a'), result, 1);
                nums[index[2]] = addChar(nums[index[2]], (char)(index[2] + 'a'), result, 1);
                count ++;
            }
        }
        if(count == 3){
            int diff = Math.min(nums[index[0]], 2);
            while(true){
                nums[index[0]] = addChar(nums[index[0]], (char)(index[0] + 'a'), result, diff);
                nums[index[1]] = addChar(nums[index[1]], (char)(index[1] + 'a'), result, diff);
                nums[index[2]] = addChar(nums[index[2]], (char)(index[2] + 'a'), result, diff);
                diff = Math.min(nums[index[0]], 2);
                if(diff == 0) break;
            }
        }
        return result.toString();
    }
    
    public int addChar(int num, char c, StringBuilder result, int diff){
        num -= diff;
        while(diff > 0){
            result.append(c);
            diff --;
        }
        return num;
    }
    
    public int[] sort(int[] nums){
        int[] index = new int[3];
        int max = -1;
        int indexMax = -1;
        int min = 101;
        int indexMin = -1;
        for(int i = 0; i < 3; i ++){
            if(max < nums[i]){
                max = nums[i];
                indexMax = i;
            }
            if(min > nums[i]){
                min = nums[i];
                indexMin = i;
            }
        }
        if(max == min) {
        	for(int i = 0; i < 3; i ++) index[i] = i;
        	return index;
        }
        index[0] = indexMax;
        index[2] = indexMin;
        index[1] = 3 - indexMax - indexMin;
        return index;
    }
}
```