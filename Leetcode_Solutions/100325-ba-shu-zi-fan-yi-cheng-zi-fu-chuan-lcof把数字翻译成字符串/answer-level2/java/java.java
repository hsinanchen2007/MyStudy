![奇怪的知识增加了.jpg](https://pic.leetcode-cn.com/b343397700cfd17eb8633c05954ad96fd96a66b42f280a4ed90f44fd6696b7ce-%E5%A5%87%E6%80%AA%E7%9A%84%E7%9F%A5%E8%AF%86%E5%A2%9E%E5%8A%A0%E4%BA%86.jpg)

### 代码

```java
class Solution {
    public int translateNum(int num) {

        if (num < 10) return 1;
        if (num < 26) return 2;
        //大于等于26，至少有两位
        int lastOne = num%10;
        int lastTwo = num%100;//获得最后两位数
        int firstOne = num/10;
        int firstTwo = num/100;//获得除了最后两位
        if(lastTwo>=10 && lastTwo<=25){
            return translateNum(firstOne)+translateNum(firstTwo);
        }else{
            return translateNum(firstOne);
        }
    }
}
```