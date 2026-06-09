### 解题思路
1.更新过程中的每个疑似快乐数n：循环取余，平方求和，余数为0则更新n。
2.判断是否快乐：n为1（ture）；n与之前的疑似n重复（false）
3.考虑到要记录所有的疑似n，使用Set集合（不能包含重复对象）。
    使用set.add(n)进行插入对象，如果对象重复，则set.add（n）= false，可以用来作为while循环的条件。
4.补充知识：Set接口常用的实现类有HashSet类(无序）和TreeSet类（有序）。

### 代码

```java
class Solution {
    public boolean isHappy(int n) {
        Set<Integer> set = new HashSet<Integer>();
//        while(set.add(n)){//set集合不允许对象重复
//           int sum = 0;
//            while(n != 0){
//                int a = 0;
//                a = n%10;
//                sum += a*a;
//                n = n/10;          
//            }
//            if(sum == 1) return true;
//            n = sum;
//        }
//        return false;
        while(set.add(n)){
            n = change(n);
            if(n == 1) return true;
        }
        return false;
    }
    public int change(int a){//建立方法更新n
        int sum = 0;
        while(a != 0){
            int b;
            b = a%10;
            sum += b*b;
            a = a/10;
        }
        return sum; 
    }
}
```
### 解题思路
使用双指针

### 代码

```java
class Solution {
    public boolean isHappy(int n) {
        //使用快慢指针，慢指针进行一步，快指针进行两部，当它俩相等时则为一个周期结束
        int slow = n;
        int fast = n;
        do{
            slow = change(slow);
            fast = change(fast);
            fast = change(fast);
        }while(slow != fast);
        return slow == 1 ;      
    }
    public int change(int a){
        int sum = 0;
        while(a != 0){
            int b;
            b = a % 10;
            sum += b*b;
            a = a/10;
        }
        return sum;
    }
}
```