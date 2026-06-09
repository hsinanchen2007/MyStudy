### 解题思路
这题一开始超时了,可以优化的点有:
1.最开始是想遍历wordList找出所有响铃的点,这个时间复杂度就大了,O(n^2);这是导致结果一直超时的罪魁祸首
2.visited,不用set用boolean[]更快
3.双向遍历

### 代码

```java
class Solution {
    
     class Node {

        Set<Node> next = new HashSet<>();

        String val;

        public Node(String val) {
            this.val = val;
        }
    }

    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        Map<String, Node> nodeMap = new HashMap<>();
        boolean contains = false;
        int n = beginWord.length();
        for (String s : wordList) {
            if (s.equals(endWord)) {
                contains = true;
            }
            Node curNode = new Node(s);
            char[] chars = s.toCharArray();
            for (int i = 0; i < n; i++) {
                for (int j = 'a'; j <= 'z'; j++) {
                    chars[i] = (char) j;
                    String s1 = new String(chars);
                    if (nodeMap.containsKey(s1)) {
                        Node nextNode = nodeMap.get(s1);
                        nextNode.next.add(curNode);
                        curNode.next.add(nextNode);
                    }
                    chars[i] = s.charAt(i);
                }
            }
            nodeMap.put(s, curNode);
        }
        if (!contains) {
            return 0;
        }
        Node beginNode = new Node(beginWord);
        char[] chars = beginWord.toCharArray();
        for (int i = 0; i < n; i++) {
            for (int j = 'a'; j <= 'z'; j++) {
                chars[i] = (char) j;
                String s1 = new String(chars);
                if (nodeMap.containsKey(s1)) {
                    Node nextNode = nodeMap.get(s1);
                    beginNode.next.add(nextNode);
                }
                chars[i] = beginWord.charAt(i);
            }
        }
        
        
//        for (String s1 : nodeMap.keySet()) {
//            if (isNext(beginWord, s1)) {
//                Node nextNode = nodeMap.get(s1);
//                beginNode.next.add(nextNode);
//            }
//        }
        Set<String> visited = new HashSet<>();
        nodeMap.put(beginWord, beginNode);
        visited.add(beginWord);
        int result = 1;
        Set<String> curStrs = new HashSet<>();
        curStrs.add(beginWord);
        while (visited.size() < nodeMap.size()) {
             if (curStrs.size() == 0) {
                break;
            }
            result++;
            Set<String> nextStrs = new HashSet<>();
            for (String curStr : curStrs) {
                Node node = nodeMap.get(curStr);
                for (Node node1 : node.next) {
                    if (!visited.contains(node1.val)) {
                        visited.add(node1.val);
                        nextStrs.add(node1.val);
                    }
                }
            }
            if (nextStrs.contains(endWord)) {
                return result;
            } else {
                curStrs = nextStrs;
            }
        }
        return 0;

        //        int[] curResult = new int[1];
        //        curResult[0] = Integer.MAX_VALUE;
        //        length(nodeMap, beginWord, endWord, visited, curResult, 0);
        //        int result = curResult[0];
        //        if (result == Integer.MAX_VALUE) {
        //            return 0;
        //        } else {
        //            return result;
        //        }
    }

    public void length(Map<String, Node> nodeMap, String curWord, String endWord,
            Set<String> visited, int[] curResult, int curStep) {
        if (curStep >= curResult[0]) {
            return;
        }
        curStep++;
        if (curWord.equals(endWord)) {
            if (curStep < curResult[0]) {
                curResult[0] = curStep;
            }
        } else {
            visited.add(curWord);
            for (Node node : nodeMap.get(curWord).next) {
                if (!visited.contains(node.val)) {
                    length(nodeMap, node.val, endWord, visited, curResult, curStep);
                }
            }
            visited.remove(curWord);
        }
    }

    private boolean isNext(String s1, String s2) {
        int diff = 0;
        for (int i = 0; i < s1.length(); i++) {
            if (s1.charAt(i) != s2.charAt(i)) {
                diff++;
                if (diff >= 2) {
                    return false;
                }
            }
        }
        return true;
    }

}

```