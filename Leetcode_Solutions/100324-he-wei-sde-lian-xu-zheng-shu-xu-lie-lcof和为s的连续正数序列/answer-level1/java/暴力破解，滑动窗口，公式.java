1. 等差数列公式
利用等差数列公式，先确知道有几个数n，然后根据target和n确定首项
```java
class Solution {
    public static int[][] findContinuousSequence(int target) {
        List<int[]> list = new ArrayList();
        int n = target/2 + 1;
        while(n>1){
            int res = target - n * (n-1)/2;
            if(res < 0 || res/n <=0 || res % n != 0) {
                n--;
                continue;
            }else{
                int[] temp = new int[n];
                for(int i = 0; i < n; i++)
                    temp[i] = res/n + i;
                list.add(temp);
            }
            n--;

        }
        return list.toArray(new int[list.size()][]);
    }
}
```


2. 滑动窗口
```java
class Solution {
    public static int[][] findContinuousSequence(int target) {
        List<int[]> list = new ArrayList();
        int i = 1; //滑动窗口左边界  一开始窗口只有一个值1
        int j = 1;  //滑动窗口有边界
        int sum = 0;  //窗口内部的值
        while( i <= target/2){
            if(sum < target){  //滑动窗口右边界向右移动
                sum += j;
                j++;
            } else if(sum > target){ //整个窗口向右移动
                sum -= i;
                i++;
            } else {                   //满足条件，整个窗口向右移动
                int[] temp = new int[j - i];
                for(int k = 0; k < j-i; k++){
                    temp[k] = k + i;
                }
                list.add(temp);
                sum -= i;
                i++;
            }
            
        }
        return list.toArray(new int[list.size()][]);
    }
}
```
双100%

```java
class Solution {
    public static int[][] findContinuousSequence(int target) {
        List<int []> list = new ArrayList<>();
        int n = 2;
        int res = target - n * (n -1)/2;
        while(res > 0){   
            if(res%n == 0){
                int[] temp = new int [n];
                for(int i = 0; i < n; i++){
                    temp[i] = res/n + i;
                }
                list.add(temp);
            }
            n++;
            res = target - n * (n -1)/2;
        }
        Collections.reverse(list);
        return list.toArray(new int[list.size()][]);
    }
}
```

3. 暴力破解
```java
class Solution {
    public static int[][] findContinuousSequence(int target) {
        List<int[]> list = new ArrayList();
        for(int i = 1; i <= target/2 + 1; i++){
            int sum = i;
            for(int j = i + 1; j <= target/2 + 1; j++){
                sum += j;
                if(sum == target){
                    int[] temp = new int[j - i + 1];
                    for(int k = 0; k < j- i + 1; k++){
                        temp[k] = k + i;
                    }
                    list.add(temp);
                } else if(sum >target){
                    break;
                }
            }
        }
        return list.toArray(new int[list.size()][]);
    }
}
```
