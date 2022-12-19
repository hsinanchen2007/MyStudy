


class Solution {
    public boolean buddyStrings(String A, String B) {
        if (A.length() != B.length() || A.length() <= 1) {
            return false;
        }
        String[] a = A.split("");
        String[] b = B.split("");
        Set<String> set = new TreeSet<>();
        for (String item : a) {
            set.add(item);
        }
        int count = 0, first = -1, second = -2;

        for (int i = 0; i < a.length; i++) {
            if (!(a[i].equals(b[i]))) {
                count++;
                if (count == 1) {
                    first = i;
                }
                if (count == 2) {
                    second = i;
                }
                if (count > 2) {
                    return false;
                }
            }
        }
        //count 0:相同，此时需要判断有无重复元素  1：有一个不同,无法交换 2：有两个不同，交换彼此进行判断 
        if (count == 1) {
            return false;
        }
        if (count == 2 && a[first].equals(b[second]) && a[second].equals(b[first]))
            return true;
        if (count == 2 && (!a[first].equals(b[second]) || !a[second].equals(b[first])))
            return false;
        //为0只要存在重复元素即可
        if (count == 0 && set.size() != A.length()) {
            return true;
        } else {
            return false;
        }
    }
}