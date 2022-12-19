
### 执行结果：
![1573463735363-image.png](https://pic.leetcode-cn.com/2d7d976699616abf97e559545eff8aa0867d82f62ae32d70a1ead3d382036358-1573463735363-image.png)

### 实现代码：
```
class Solution {
    public int compareVersion(String version1, String version2) {
        int[] arr1 = toArray(version1);
        int[] arr2 = toArray(version2);

        int len = arr1.length >= arr2.length ? arr1.length : arr2.length;

        arr1 = paddingArray(arr1, len);
        arr2 = paddingArray(arr2, len);

        for(int i=0;i<len;i++){
            int i1 = arr1[i];
            int i2 = arr2[i];
            if(i1 > i2){
                return 1;
            }
            if(i1 < i2){
                return -1;
            }
            continue;
        }
        return 0;
    }
    
    private int[] toArray(String version){
        List<String> list = split(version,'.');
        int len = list.size();
        int[] result = new int[len];
        for(int i=0;i<len;i++){
            result[i] = Integer.valueOf(list.get(i));
        }
        return result;
    }

    private int[] paddingArray(int[] arr, int length) {
        if (arr.length == length) {
            return arr;
        }

        int[] result = new int[length];

        System.arraycopy(arr, 0, result, 0, arr.length);

        return result;
    }

    private List<String> split(String s, char seperator){
        char[] chars = s.toCharArray();
        char[] copied = new char[chars.length];

        List<String> result = new ArrayList<String>();

        int size = 0;
        for(char c : chars){
            if(c == seperator){
                if(size == 0){
                    continue;
                }
                result.add(new String(Arrays.copyOf(copied, size)));
                size = 0;
                continue;
            }
            copied[size++] = c;
        }
        
        if(size > 0){
            result.add(new String(Arrays.copyOf(copied, size)));
        }

        return result;
    }
}
```
