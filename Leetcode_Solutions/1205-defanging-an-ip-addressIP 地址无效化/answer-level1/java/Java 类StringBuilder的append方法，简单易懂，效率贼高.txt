![屏幕截图(2).png](https://pic.leetcode-cn.com/14c7ebce9259fe73fd07a4611652a2b214bb9e8bfd048b1714695657ae280a61-%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE\(2\).png)





```
class Solution {
    public String defangIPaddr(String address) {
        StringBuilder res = new StringBuilder();

        for(char ch : address.toCharArray()){
            if(ch == '.'){
                res.append("[.]");
            }else
                res.append(ch);
        }
        return res.toString();
    }
}
```
