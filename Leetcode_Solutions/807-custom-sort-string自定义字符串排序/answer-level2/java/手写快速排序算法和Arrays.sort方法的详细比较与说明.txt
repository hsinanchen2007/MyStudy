思路：此题，题意很明确，让我们按照S中的排序规则，对T进行排序，实际上考察大家对排序算法的熟练程度，十大排序算法，不知道大家熟练几种呢？此题解向大家介绍快速排序。

解法一：利用ArraysAPI进行自定义排序，借助Arrays.sort实现，需注意的是，重载的compare方法需要满足，__自反性，对称性，和传递性__，否则可能会报异常：java.lang.IllegalArgumentException: Comparison method violates its general co***act!，这是个比较高级的异常，较为少见。效率分析，库函数使用的排序算法是经过优化过后的快速排序算法，一般的时间复杂度是O(n*logn)，__此解法效率拖累在于来回拷贝数组，因为Arrays.sort方法不能直接对char数组进行自定义的排序，而char数组也不能直接转换为其对应的包装类的数组。__
```
class Solution {
    public String customSortString(String S, String T) {
        char[] cs = T.toCharArray();
        Character ccs[] = new Character[cs.length];
        for (int i = 0;i < cs.length;i++) {
            ccs[i] = cs[i];
        }

        Arrays.sort(ccs,new Comparator<Character>() {

            @Override
            public int compare(Character a, Character b) {
                int indexA = S.indexOf(a);
                int indexB = S.indexOf(b);

                if (indexA < 0 && indexB < 0) {
                    return 0;
                }

                if (indexA < 0 && indexB > 0) {
                    return -1;
                }

                if (indexA > 0 && indexB < 0) {
                    return 1;
                }

                if (indexA > indexB) {
                    return 1;
                }

                if (indexA < indexB) {
                    return -1;
                }

                if (indexA == indexB) {
                    return 0;
                }

                return a > b ? 1 : a == b ? 0 : -1;
            }
        });

        for (int i = 0;i < cs.length;i++) {
            cs[i] = ccs[i];
        }

        return new String(cs);
    }
}
```
解法二：按照S中的规则，手写快速排序算法，快速排序算法关键在于找划分，找划分的关键在于比大小，比大小的关键在于S中的规则，效率分析，快排的时间复杂度为O(n*logn)
```
class Solution {
    String rule;
    public String customSortString(String S, String T) {
        this.rule = S;
        char[] cs = T.toCharArray();
        quickSort(cs,0,cs.length - 1);
        return new String(cs);
    }
    
    private void quickSort(char[] sort,int left,int right) {
        if (left < right) {
            int pt = partition(sort,left,right);
            quickSort(sort,left,pt - 1);
            quickSort(sort,pt + 1,right);
        }
    }
    
    private int partition(char[] sort,int left,int right) {
        char temp = sort[left];
        
        while (left < right) {
            while (left < right && rule.indexOf(sort[right]) > rule.indexOf(temp)) {
                right--;
            }
            
            if (left < right) {
                sort[left] = sort[right];
                left++;
            }
            
            while (left < right && rule.indexOf(sort[left]) < rule.indexOf(temp)) {
                left++;
            }
            
            if (left < right) {
                sort[right] = sort[left];
                right--;
            }
        }
        
        sort[left] = temp;
        return left;
    }
}
```