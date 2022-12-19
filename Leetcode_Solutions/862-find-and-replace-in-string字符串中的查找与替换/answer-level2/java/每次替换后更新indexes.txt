```
class Solution {
    public String findReplaceString(String S, int[] indexes, String[] sources, String[] targets) {
        StringBuilder sb = new StringBuilder(S);
        for(int i = 0; i < sources.length; i++){
            if(swap(sb, indexes[i], sources[i], targets[i])) {
                updateIndexes(indexes, sources[i].length(), targets[i].length(), indexes[i]);
            }
        }

        return sb.toString();
    }

    public void updateIndexes(int[] indexes, int source_l, int target_l, int ori_i) {
        for(int i = 0; i < indexes.length; i++) {
            if(indexes[i] > ori_i) {
                indexes[i] += target_l-source_l;
            }
        }
    }

    public boolean swap(StringBuilder sb, int start, String source, String target) {
        if(sb.indexOf(source, start) == start) {
            sb.delete(start, start+source.length());
            sb.insert(start, target);
            return true;
        } else {
            return false;
        }
    }
}
```

在每次替换后，更新indexes。
将每一个比当前index大的index都加上当前source长度和当前target长度的差，得出替换后indexes的正确位置。再次进行替换。

