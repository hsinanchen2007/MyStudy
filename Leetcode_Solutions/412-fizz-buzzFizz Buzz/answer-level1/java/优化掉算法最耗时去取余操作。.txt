### 解题思路
题目简单，但如何才能高效计算，优化掉算法最耗时去取余操作。


### 代码

```优先填充
class Solution {
    public List<String> fizzBuzz(int n) {
        String[] list=new String[n];
        for (int index=2;index<n;index+=3)
            list[index]="Fizz";
        for (int index=4;index<n;index+=5) {
            if ((null == list[index])) {
                list[index] = "Buzz";
            } else {
                list[index] = "FizzBuzz";
            }
        }
        for (int index=0;index<n;index++) {
            if (null == list[index]) {
                list[index] = String.valueOf(index+1);
            }
        }
        return Arrays.asList(list);
    }
}
```
```计数法
public List<String> fizzBuzz(int n) {
        List<String> list=new ArrayList<>(n);
        int count3=1,count5=1;
        for (int index=1;index<=n;index++,count3++,count5++){
            if(count5==5 && count3==3){
                list.add("FizzBuzz");
                count3=0;
                count5=0;
            }else if(count5==5){
                list.add("Buzz");
                count5=0;
            }else  if(count3==3){
                list.add("Fizz");
                count3=0;
            }else {
                list.add(String.valueOf(index));
            }
        }
        return list;
    }
```