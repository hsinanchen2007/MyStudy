### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String intToRoman(int num) {
         StringBuilder stringBuilder=new StringBuilder();
        int[] arrays=new int[]{1,4,5,9,10,40,50,90,100,400,500,900,1000};
        HashMap<Integer,String>hashMap=new HashMap<>();
        Stack<Integer>stack=new Stack<>();

        hashMap.put(1,"I");
        hashMap.put(5,"V");
        hashMap.put(4,"IV");
        hashMap.put(9,"IX");
        hashMap.put(10,"X");
        hashMap.put(40,"XL");
        hashMap.put(50,"L");
        hashMap.put(90,"XC");
        hashMap.put(100,"C");
        hashMap.put(400,"CD");
        hashMap.put(500,"D");
        hashMap.put(900,"CM");
        hashMap.put(1000,"M");

        if(hashMap.containsKey(num)){
            return hashMap.get(num);
        }

        for(int i=0;i<arrays.length;i++){
            stack.push(arrays[i]);
        }

        while(!stack.isEmpty()){
            if(stack.peek()>num){
                stack.pop();
            }else{
                stringBuilder.append(hashMap.get(stack.peek()));
                num=num-stack.peek();
            }
        }

        return stringBuilder.toString();
    }
}
```