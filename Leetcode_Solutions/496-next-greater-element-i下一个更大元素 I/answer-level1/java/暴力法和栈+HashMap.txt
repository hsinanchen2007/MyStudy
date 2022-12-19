暴力法
```
public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        for (int i = 0; i < nums1.length; i++) {
            for (int j = 0; j < nums2.length; j++) {
                if (nums1[i]==nums2[j]) {
                    boolean ok=true;
                    for (int j2 = j+1; j2 < nums2.length; j2++) {
                        if (nums1[i]<nums2[j2]) {
                            nums1[i]=nums2[j2];
                            ok=false;
                            break;
                        }
                    }
                    if (ok) {
                        nums1[i]=-1;
                    }
                    break;
                }
            }
        }
        return nums1;
    }
```

栈+HashMap
```
public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        Map<Integer, Integer> map=new HashMap<>();
        Stack<Integer> stack=new Stack<Integer>();
        for (int i = 0; i < nums2.length; i++) {
            while (!stack.isEmpty() && nums2[i]>stack.peek()) {
                map.put(stack.pop(), nums2[i]);
            }
            stack.push(nums2[i]);
        }
        for (int i = 0; i < nums1.length; i++) {
            nums1[i]=map.getOrDefault(nums1[i], -1);
            }
        return nums1;
    }
```
