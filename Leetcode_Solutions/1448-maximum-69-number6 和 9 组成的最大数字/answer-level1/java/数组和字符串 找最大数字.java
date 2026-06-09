### 解题思路
好幼稚....好复杂......

### 代码

```java
class Solution {
    public int maximum69Number (int num) {
        int geshu=String.valueOf(num).length();
//        System.out.println(geshu);
        int[] nums=new int[geshu];
        for (int i = 0; i < geshu; i++) {
//            System.out.println(String.valueOf(num).charAt(i));
            nums[i]=String.valueOf(num).charAt(i)-48;
//            System.out.println(nums[i]);
//            System.out.println("*************");
        }

        for (int i=0;i<geshu;i++){
            if(nums[i]==6){
                nums[i]=9;
                break;
            }
        }
        int out=0;
        for (int i = 0; i < geshu; i++) {
            // System.out.println(nums[i]);
            out +=nums[i]*Math.pow(10,geshu-i-1);
        }
        return out;
    }
}
```