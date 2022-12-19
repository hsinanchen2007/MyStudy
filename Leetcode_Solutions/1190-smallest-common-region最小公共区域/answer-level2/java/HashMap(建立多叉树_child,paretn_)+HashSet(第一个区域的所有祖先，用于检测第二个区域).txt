### 解题思路
此处撰写解题思路
**LCA步骤**
- 通过hashMap建立多叉树<child,parent>;已经存在则没有必要
- 使用HashSet保存`节点1`的所有祖先节点,`anceALL1`。
- `节点2`的第一个出现在region01中的祖先节点`anceALL1`，就是最近公共祖先
![Snipaste_2020-03-22_23-52-46.png](https://pic.leetcode-cn.com/98fb4da3eda9760ac1c5882317e7aa8071113fe59cb2ebcf1b130d8d430e5f5c-Snipaste_2020-03-22_23-52-46.png)

### 代码

```java
class Solution {
    public String findSmallestRegion(List<List<String>> regions, String region1, String region2) {
        //多叉树如何建立？？？hashmap
        //保存region1的所有祖先节点。
        //regin02的第一个出现在region01中的祖先节点，就是最近公共祖先
        HashMap<String,String> ance=new HashMap<>();//<chard,parent>
        for(List<String> oneRegin:regions){
            String parent=oneRegin.get(0);
            for(int i=1;i<oneRegin.size();i++) ance.put(oneRegin.get(i),parent);   
        }
        //取出第一个区域的所有祖先
        HashSet<String> ances1=new HashSet<>();
        while(region1!=null) {
            ances1.add(region1);
            region1=ance.get(region1);//get his parent;
        }
        //查找第二个的祖先中第一次出现在ances1中。
        while(!ances1.contains(region2))region2=ance.get(region2);
        return region2;
        
    }
}
```