利用Trie树优化搜索效率，降低时间复杂度。
对于每一个单词，从后往前遍历字符串，查找在Trie树中是否有对应的单词，找到的单词拼接到当前单词判断是否为回文串。
需要注意： 
1 当前单词所有字符遍历结束后，需要检查Trie树中剩余的单词；
2 兼容空字符串
3 当前单词自身不能与自身拼接


```
class Solution {
    class TrieNode{
        TrieNode [] children;
        String word;
        Integer index;
        public TrieNode(){
            children = new TrieNode[26];
            word = null;
            index = null; 
        }
    }
    private void addWord(TrieNode root,String word,int index){
        TrieNode [] nodes = root.children;
        //如果出现空字符串，保存在Trie树根节点上
        if(word.length()==0){
            root.word = word;
            root.index = index;
        }
        for(int i=0;i<word.length();i++){
            int currIndex = word.charAt(i) -'a';
            if(nodes[currIndex]==null){
                nodes[currIndex] = new TrieNode();
            }
            if(i == word.length()-1){
                nodes[currIndex].word = word;
                nodes[currIndex].index = index;
            }
            nodes = nodes[currIndex].children;
        }
    }

    public List<List<Integer>> palindromePairs(String[] words) {
        List<List<Integer>> result = new ArrayList();
        TrieNode root = new TrieNode();
        for(int i=0;i<words.length;i++){
            addWord(root,words[i],i);
        }
        for(int i=0;i<words.length;i++){
            findPalindrome(i,words[i],root,result);
        }
        return result;
    }
    private void findPalindrome(int index,String word,TrieNode root,List<List<Integer>> result){
        TrieNode nextNode = root;
        //判断空字符串
        if(root!=null && root.word!=null && root.index!=index && isPalindrome(word)){
            result.add(Arrays.asList(root.index,index));
        }
        for(int i=word.length()-1;i>=0;i--){
            int charIndex = word.charAt(i) - 'a';
            if(nextNode==null){
                break;
            }
            TrieNode currNode = nextNode.children[charIndex];
            if(currNode!=null && currNode.word!=null && currNode.index !=index &&  isPalindrome(currNode.word+word)){
                    result.add(Arrays.asList(currNode.index,index));
            }
            nextNode = currNode;
        }
        //遍历Trie树中字符筛选剩余的word，并判断是否为回文。注意这里不能从nextNode开始，应该从nextNode的下一层开始
        List<TrieNode> leftNodes = new ArrayList();
        if(nextNode!=null){
            for(TrieNode node:nextNode.children){
                getLeftNode(node,leftNodes);
            }
        }
        for(TrieNode node:leftNodes){
            if(isPalindrome(node.word+word) && node.index!=index){
                result.add(Arrays.asList(node.index,index));
            }
        }
    }

    //dfs获取剩余Trie树中剩余的word
    private void getLeftNode(TrieNode node,List<TrieNode> leftNodes){
        if(node==null){
            return ;
        }
        if(node!=null && node.word!=null){
            leftNodes.add(node);
        }
        for(TrieNode child:node.children){
            getLeftNode(child,leftNodes);
        }
    }

    private boolean isPalindrome(String word){
        int n = word.length();
        int step = n/2;
        for(int i=0;i<step;i++){
            if(word.charAt(i)!=word.charAt(n-1-i)){
                return false;
            }
        }
        return true;
    }


}
```
