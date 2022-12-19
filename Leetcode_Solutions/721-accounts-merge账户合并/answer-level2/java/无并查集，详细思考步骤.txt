### 解题思路
![2.png](https://pic.leetcode-cn.com/44b25c90e11220979484e0d88c5ea0b05fc9e91df1e22e767d0b75679de174a8-2.png)

无并查集，分享一下，欢迎指出意见
首先想到用Map结构，用email做key，name做value，方便进行合并操作
为了能够快速的找到每一步中，任意一个name对应的所有email,再引入一个名为reverseMap的新Map结构，key为name,value为对应的email列表，后面会解释
然后遍历account并在这个过程中逐步合并列表：

对于accounts中的每一个列表list,令它对应的账户为name,先检查该列表中的是否有email已经存在于map中了
**如果否：**
只能说明现在list和已有的数据不能合并，不能代表以后不会合并，为了区分账户相同的情况，为每个name增加一个序号。然后把email和name存入map
同时在reverseMap中增加一个键值对
**如果是：**
说明需要将list合并进去，此时确定好一个name，把map中需要合并的所有email都改成这个name
所有需要合并的email包括三个部分:
list中已经作为map的key存在的email+**这些email对应的name对应的所有email**+list中第一次遍历到的email
合并的过程包括两种情况：
1.对于已经作为key存在的email，不仅要修改这个email对应的name,还要根据原本的name查到所有相对应的email，把这些email的name也改成新的
2.对于新遍历到的email,直接存储<email,name>对
合并以后修改reverseMap,把这里的多个<name,List>对也合并起来并重新存进reverseMap

遍历结束以后直接获取reverseMap中的每一个列表即可，注意把序号再去掉

举例说明：
所有的name都一样，邮箱序列如下:(0,1)(2,3)(4,5)(1,3)(3,5)
第一步
0:name0
1:name0
第二步
0:name0
1:name0
2:name1
3:name1
第三步
0:name0
1:name0
2:name1
3:name1
4:name2
5:name2
第四步
0:name0
1:name0
2:name0
3:name0
4:name2
5:name2
第五步
0:name0
1:name0
2:name0
3:name0
4:name0
5:name0


### 代码

```java
class Solution {
    int id=0;

    public List<List<String>> accountsMerge(List<List<String>> accounts) {
        Map<String,String> map=new HashMap<String,String>();//key为email,value为name+序号
        Map<String,List<String>> reverseMap=new HashMap<String,List<String>>();//键为name+序号，value为对应的email列表
        for(List<String> list:accounts){
            String name=null;
            for(int i=1;i<list.size();i++){
                if(map.containsKey(list.get(i))){
                    name=map.get(list.get(i));
                    break;
                }
            }
            name=name==null?list.get(0)+getNextId():name;
            List<String> emailList=null;
            if(reverseMap.containsKey(name)){
                emailList=reverseMap.get(name);
            }else{
                emailList=new ArrayList<String>();
            }
            for(int i=1;i<list.size();i++){
                String email=list.get(i);
                if(map.containsKey(email)){//如果找到了map中已经含有的email
                    //如果此时的账户名不同，则把这个账户下面的email合并过来
                    if(!map.get(email).equals(name)){
                        String tmpName=map.get(email);
                        List<String> tmpEmailList=reverseMap.get(tmpName);
                        for(String tmpEmail:tmpEmailList){
                            map.put(tmpEmail,name);
                        }
                        emailList.addAll(tmpEmailList);
                        reverseMap.remove(tmpName);
                    }
                    //如果账户名相同则不操作
                }else{//如果没找到这个email则直接添加
                    map.put(email,name);
                    emailList.add(email);
                }
            }
            reverseMap.put(name,emailList);
        }

        List<List<String>> ans=new ArrayList<List<String>>();
        for(Map.Entry<String,List<String>> entry:reverseMap.entrySet()){
            //最后要把序号去掉
            //新增：此题暗含email需要一个字典序排序
            List<String> value=entry.getValue();
            Collections.sort(value);
            String name=entry.getKey();
            int len=name.length();
            name=name.substring(0,len-3);
            value.add(0,name);
            ans.add(value);
        }
        return ans;
    }

    //List最大1000项，因此设置三位的序号000-999用来区分同一个name
    public String getNextId(){
        if(id<10){
            return "00"+id++;
        }else if(id<100){
            return "0"+id++;
        }else{
            return ""+id++;
        }
    } 
}
```