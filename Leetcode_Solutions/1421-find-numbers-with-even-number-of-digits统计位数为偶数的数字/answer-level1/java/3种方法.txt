# 1. 把数字转成字符串
```java
public int findNumbers(int[] nums) {
    int count = 0;
    for (int i = 0; i < nums.length; i++) {
        if (String.valueOf(nums[i]).length() % 2 == 0) {
            count++;
        }
    }
    return count;
}
```
# 2. 数字循环除10，统计等于0的时候除10的次数，偶数次则该数为偶数位
```java
public int findNumbers(int[] nums) {
    int count = 0;
    for (int i = 0; i < nums.length; i++) {
        int N = nums[i];
        //记录除10的次数
        int countTen = 0;
        while (N != 0) {
            N/=10;
            countTen++;
        }
        //如果除10的次数是偶数次，则该数为偶数位数
        if (countTen % 2 == 0) {
            count++;
        }
    }
    return count;
}
```
# 3. 已知范围为1 <= nums[i] <= 10^5，所以只有两个区间内的数为偶数位10~99以及1000~9999
```java
public int findNumbers(int[] nums) {
    int count=0;
    for(int i=0;i<nums.length;++i){
        if((nums[i]>=10&&nums[i]<100)||(nums[i]>=1000&&nums[i]<10000))
            count++;
    }
    return count;        
}
```
