### 解题思路
这个题与LeetCode_214题"最短回文串"，思路差不多
只不过这里是寻找该字符串能够组成的所有回文串，核心算法与214题差不多

### 代码

```java
class Solution {
    /*
    * 基本思路：
    * 1、将字符串存入map中  key为字符串，value为在数组中的下标
    * 2、遍历字符串数组，将每一个字符串组成所有可能的回文串（可以参考214题），缺少的部分从map中寻找
    * 3、若map中存在，加入结果list中
    */
    public List<List<Integer>> palindromePairs(String[] words) {
        List<List<Integer>> lists = new LinkedList<List<Integer>>();
        Map<String,Integer> map = new HashMap<String,Integer>();
        for(int i=0;i<words.length;i++){
            map.put(words[i],i);
        }
        for(int i=0;i<words.length;i++){
            String sb = words[i];
            if(sb.equals("")) continue;
            String key = "";
            //判断字符串本身是不是回文串
            int left = 0;
            int right = sb.length()-1;
            while(left<=right){
                if(sb.charAt(left)!=sb.charAt(right)){
                    break;
                }
                left++;
                right--;
            }
            if(left>right){
                isAddToListsLeft(key,map,lists,i);
                isAddToListsRight(key,map,lists,i);
            }

            for(int cur=0;cur<sb.length();cur++){
                //以当前节点为中心，向两边扩散
                left = cur-1;
                right = cur+1;
                while(left>=0 && right<sb.length()){
                    if(sb.charAt(left)!=sb.charAt(right)){
                        break;
                    }
                    left--;
                    right++;
                }
                if(right==sb.length() && left>=0){//左边有剩余
                    key = sb.substring(0,left+1);
                    StringBuilder temp = new StringBuilder(key);
                    key = temp.reverse().toString();
                    // System.out.println(sb+" &&  "+key);
                    isAddToListsRight(key,map,lists,i);
                }
                if(left<0 && right<sb.length()){//右边有剩余
                    key = sb.substring(right,sb.length());
                    StringBuilder temp = new StringBuilder(key);
                    key = temp.reverse().toString();
                    // System.out.println(key+" --  "+sb);
                    isAddToListsLeft(key,map,lists,i);
                }
                //以当前节点与右边节点为中心，向两边扩展
                left = cur;
                right = cur+1;
                while(left>=0 && right<sb.length()){
                    if(sb.charAt(left)!=sb.charAt(right)){
                        break;
                    }
                    left--;
                    right++;
                }
                if(right==sb.length() && left>=0){//左边有剩余
                    key = sb.substring(0,left+1);
                    StringBuilder temp = new StringBuilder(key);
                    key = temp.reverse().toString();
                    // System.out.println(sb+" &&  "+key);
                    isAddToListsRight(key,map,lists,i);
                }
                if(left<0 && right<sb.length()){//右边有剩余
                    key = sb.substring(right,sb.length());
                    StringBuilder temp = new StringBuilder(key);
                    key = temp.reverse().toString();
                    // System.out.println(key+" --  "+sb);
                    isAddToListsLeft(key,map,lists,i);
                }
            }
        }
        return lists;
    }

    public void isAddToListsRight(String key, Map<String,Integer> map, 
                                List<List<Integer>> lists, int index){
        if(map.containsKey(key)){
            int value = map.get(key);
            if(value==index) return;
            List<Integer> list = new LinkedList<Integer>();
            list.add(index);
            list.add(value);
            lists.add(list);
        }
    }

    public void isAddToListsLeft(String key, Map<String,Integer> map, 
                                List<List<Integer>> lists, int index){
        if(map.containsKey(key)){
            int value = map.get(key);
            if(value==index) return;
            List<Integer> list = new LinkedList<Integer>();
            list.add(value);
            list.add(index);
            lists.add(list);
        }
    }

}
```