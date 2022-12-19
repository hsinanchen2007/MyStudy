### 解题思路
1. 倒序遍历的将数字日志扔到末尾,也保证了它们的顺序
2. 将字符拆分成标识符与日志内容两部分
3. PS(若能将split的每部分转化为数字并倒着比大小该多好 个位>十位>百位...) 滑稽
4. 加油,加油,加油

### 代码

```java
class Solution {
    //是以单个字来排序的
    private HashMap<String,List<String>> map;
    // public String[] reorderLogFiles(String[] logs) {
    //     //先对数字日志进行排序,记录数字日志的数目. 随后对
    //     HashMap<String,List<String>> map = new HashMap<>();
    //     int nums = logs.length-1;
    //     for (int i=nums;i>-1;i--){
    //         int index = logs[i].indexOf(' ')+1;
    //         char c = logs[i].charAt(index);
    //         if (Character.isDigit(c)){
    //             swap(logs,i,nums--);
    //         } else {
    //             map.put(logs[i],Arrays.asList(logs[i].split(" ")));
    //         }
    //     }
    //     this.map = map;
    //     __solution(logs,0,nums);

    //     return logs;
    // }

    private void swap(String[] logs, int i, int j) {
        String temp = logs[i];
        logs[i] = logs[j];
        logs[j] = temp;
    }

    // [l,r] quick sort
    private void __solution(String[] logs, int l, int r){
        if(l >= r) return;
        // random
        //int random = (int) (Math.random() * (r - l + 1)) + l;
        //swap(logs,l,random);
        int j = r;
        for (int i = l+1; i <= j;){
            if (compare(logs[i],logs[l]) > 0){
                swap(logs,i,j--);
            }else {
                i++;
            }
        }
        
        swap(logs,l,j);
        __solution(logs,l,j-1);
        __solution(logs,j+1,r);
    }

    private int compare(String target, String comp) {
        if (target.equals(comp)) return 0;
        List<String> v1 = map.get(target);
        List<String> v2 = map.get(comp);
        int min = Math.min(v1.size(),v2.size());
        for (int i=1;i < min;i++){
            int result = v1.get(i).compareTo(v2.get(i));
            if (result != 0)
                return result;
        }
        if (v1.size() > v2.size()){
            return 1;
        }else if (v1.size() < v2.size()){
            return -1;
        }
        return v1.get(0).compareTo(v2.get(0));
    }


    public String[] reorderLogFiles(String[] logs) {

        int nums = logs.length-1;
        int chars = 0;
        Log[] logArr = new Log[nums];
        for (int i=nums;i>-1;i--){
            char c = logs[i].charAt(logs[i].length()-1);
            if (Character.isDigit(c)){
                swap(logs,i,nums--);
            } else {
                logArr[chars++] = new Log(logs[i]);
            }
        }

        Arrays.sort(logArr, 0, chars);

        for (int i = 0; i < chars; i++) {
            logs[i] = logArr[i].getOriginalLog();
        }

        return logs;
    }

    private <T> void swap(T[] arr, int i, int j) {
        T tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }

    private class Log implements Comparable<Log> {

        private String originalLog;
        private String flag;
        private String content;

        Log(String originalLog) {
            this.originalLog = originalLog;

            initLog();
        }

        String getOriginalLog() {
            return this.originalLog;
        }

        private void initLog() {
            int delimiterIdx = originalLog.indexOf(' ');

            this.flag = originalLog.substring(0, delimiterIdx);
            this.content = originalLog.substring(delimiterIdx + 1);
        }

        @Override
        public int compareTo(Log log) {           
            int tmp = this.content.compareTo(log.content);
            if (tmp == 0) {
                return this.flag.compareTo(log.flag);
            }

            return tmp;
        }
    }
}
```