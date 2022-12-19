### 解题思路
字符肯定是以"/"分割的，所以分割字符得到一个字符数组。
. ：表示保持原来位置
.. ：表示返回上一级退栈，如果到达根路径，就不需要退，所以以"/"初始化路径
/路径： 表示前进压栈

因最终路径要顺序遍历出来，所以我用数组尾插尾删来实现栈的用法，代码如下。

### 代码

```java
class Solution {
    public String simplifyPath(String path) {
        if (path == null || path.length() == 0){
            throw new IllegalArgumentException();
        }
        String[] nodes = path.split("/");
        List<String> entityPath = new ArrayList<>();
        int index = 0;
        StringBuilder stringBuilder = new StringBuilder("/");
        for (String node : nodes){

            if(".".equals(node) || "".equals(node)){
                continue;
            }

            if("..".equals(node)){
                if(index > 0){
                    entityPath.remove(--index);
                }
            } else {
                entityPath.add(index++,node);
            }

        }

        for(String p : entityPath){
            if(index == 0){
                break;
            }
            stringBuilder.append(p);
            index--;
            if(index != 0){
                stringBuilder.append("/");
            }
        }

        return stringBuilder.toString();
    }
}
```