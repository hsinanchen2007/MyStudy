套用一下247题的解法,得到从长度在n位数之间的所有中心对称数
当low.length()=high.length()的时候，先得到从长度在low.length()之间的所有中心对称数,
然后用二分法得到在low和high之间的中心对称数;
当low.length()< high.length()的时候,先得到长度在low.length()之间的所有中心对称数,
然后用二分法得到在low和列表长度之间的中心对称数;再加上长度在low.length()+1和high.length()-1
之间的中心对称数;最后再用二分法得到长度在high.length()之间的所有中心对称数,然后加上在0到
high之间的中心对称数。
代码如下:
```
class Solution {
    public int strobogrammaticInRange(String low, String high) {

        int l = low.length();
        int h = high.length();
        if (l > h || (Long.valueOf(low) > Long.valueOf(high))) {
            return 0;
        }
        if (l == h) {
            List<String> list = findStrobogrammatic(l);
            int startIndex = getStartIndex(list, low);
            int endIndex = getEndIndex(list, high);
            if (startIndex > endIndex) {
                return 0;
            } else {
                return endIndex - startIndex + 1;
            }
        } else if (l < h) {
            int res = 0;
            List<String> leftList = findStrobogrammatic(l);
            int starIndex = getStartIndex(leftList, low);
            res += leftList.size() - starIndex;
            for (int i = l + 1; i < h; i++) {
                res += findStrobogrammatic(i).size();
            }
            List<String> rightList = findStrobogrammatic(h);
            int endIndex = getEndIndex(rightList, high);
            if (endIndex >= 0) {
                res += endIndex + 1;
            }
            return res;
        }
        return 0;
    }

    private int getEndIndex(List<String> list, String high) {
        int left = 0, right = list.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int diff = list.get(mid).compareTo(high);
            if (diff > 0) {
                right = mid - 1;
            } else if (diff < 0) {
                left = mid + 1;
            } else {
                return mid;
            }
        }
        return right;
    }

    private int getStartIndex(List<String> list, String low) {
        int left = 0, right = list.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int diff = list.get(mid).compareTo(low);
            if (diff > 0) {
                right = mid - 1;
            } else if (diff < 0) {
                left = mid + 1;
            } else {
                return mid;
            }
        }
        return left;
    }

    public List<String> findStrobogrammatic(int n) {
        List<String> ans = new ArrayList<>();
        char[] buf = new char[n];
        dfs(ans, buf, 0, n - 1);
        return ans;
    }

    private void dfs(List<String> ans, char[] buf, int l, int r) {
        if (l > r) {
            ans.add(String.valueOf(buf));
            return;
        } else if (l == r) {
            buf[l] = '0';
            ans.add(String.valueOf(buf));
            buf[l] = '1';
            ans.add(String.valueOf(buf));
            buf[l] = '8';
            ans.add(String.valueOf(buf));
            return;
        }

        if (l > 0) {
            buf[l] = '0';
            buf[r] = '0';
            dfs(ans, buf, l + 1, r - 1);
        }

        buf[l] = '1';
        buf[r] = '1';
        dfs(ans, buf, l + 1, r - 1);

        buf[l] = '6';
        buf[r] = '9';
        dfs(ans, buf, l + 1, r - 1);

        buf[l] = '8';
        buf[r] = '8';
        dfs(ans, buf, l + 1, r - 1);

        buf[l] = '9';
        buf[r] = '6';
        dfs(ans, buf, l + 1, r - 1);
    }
}
```

