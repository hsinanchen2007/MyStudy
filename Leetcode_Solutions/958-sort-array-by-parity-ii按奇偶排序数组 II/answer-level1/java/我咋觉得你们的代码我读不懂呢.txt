思路：找到奇指针不满足的位置；找到偶指针不满足的位置；交换即可；
```java
    public static int[] sortArrayByParityII(int[] arr) {
        if(arr.length<2){//边界
            return arr;
        }

        int odd=1;    //奇指针
        int even=0;  //偶指针

        while(odd<arr.length&&even<arr.length){
            //找到奇指针对应的数不为奇数的地方
            while (odd<arr.length&&arr[odd]%2!=0){
                odd+=2;
            }
            //找到偶指针对应的数不为偶数的地方
            while(even<arr.length&&arr[even]%2==0){
                even+=2;
            }
            if(odd<arr.length&&even<arr.length){
                swap(arr,odd,even);
            }
        }
        return arr;
    }

    private static void swap(int[] arr, int odd, int even) {
        int tmp=arr[odd];
        arr[odd]=arr[even];
        arr[even]=tmp;
    }