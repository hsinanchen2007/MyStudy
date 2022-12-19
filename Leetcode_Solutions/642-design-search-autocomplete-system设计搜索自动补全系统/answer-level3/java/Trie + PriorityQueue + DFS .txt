dfs出所有prefix的情况加入到优先队列中(一个情况包含了 1. 该句子出现次数 2. 该句子的文本内容)
自定义一个comparable的属性，然后在PriorityQueue中取出三个（不足3个时全部取出）。
维护一个StringBuilder在用户输入#时insert这个StringBuilder到trie中
值得注意的是，当我们遇到一整个完整的句子后 还要对当前节点继续遍历 不可以return否则会丢掉一些句子
```
class AutocompleteSystem {
    Trie trie;
    public AutocompleteSystem(String[] sentences, int[] times) {
      //initialize trie
      trie = new Trie();
      for(int i = 0; i < sentences.length; i++){
        for(int j = 0; j < times[i]; j++){
          trie.insert(sentences[i]);
        }
      }
    }
    
    public List<String> input(char c) {
      return trie.getResult(c);
    }
}

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem obj = new AutocompleteSystem(sentences, times);
 * List<String> param_1 = obj.input(c);
 */


class Trie{
  public Node root;
  public StringBuilder sb;

  public Trie(){
    root= new Node();
    sb = new StringBuilder();

  }

  private class Cell implements Comparable<Cell>{
    public int end;
    public String str;
    public Cell(int end, String str){
      this.end = end;
      this.str = str;
    }
    @Override
    public int compareTo(Cell e){
      int firstCmp = -Integer.compare(this.end, e.end);
      if(firstCmp == 0){
        return this.str.compareTo(e.str);
      }
      return firstCmp;
    }
  }

  private class Node{
    public String str = ""; // the str
    public int end = 0; // if ends at this node, and the times
    public Node[] branches = new Node[27]; // a - z + space
  }

  public List<String> getResult(char c){
    List<String> ret = new ArrayList<>();
    if(c == '#'){
      insert(sb.toString());
      sb.delete(0, sb.length());
      return ret;
    }
    sb.append(c);
    Node cur = root;
    for(int i = 0; i < sb.length(); i++){
      int idx = sb.charAt(i) == ' ' ? 26 : sb.charAt(i) - 'a';
      if(cur.branches[idx] == null){
        return ret;
      }
      cur = cur.branches[idx];
    }
    // 来到分叉路口, 开始遍历所有可能的解，并且加入到一个priorityQueue中, 考虑使用dfs
    PriorityQueue<Cell> pq = new PriorityQueue<>();
    dfs(pq, cur);
    int forLoop = pq.size() > 3 ? 3 : pq.size();
    for(int i = 0; i < forLoop; i++){
      ret.add(pq.poll().str);
    }

    return ret;
  }

  public void dfs(PriorityQueue<Cell> pq, Node node){
    if(node.end > 0){
      pq.add(new Cell(node.end, node.str));
      //这里不可以return 而是要让他继续走下去
    }
    for(int i = 0; i < 27; i++){
      if(node.branches[i] != null){
        dfs(pq, node.branches[i]);
      }
    }
  }

  public void insert(String str){
    Node cur = root;
    for(int i = 0; i < str.length(); i++){
      int idx = str.charAt(i) == ' ' ? 26 : str.charAt(i) - 'a';
      if(cur.branches[idx] == null){
        cur.branches[idx] = new Node();
      }
      cur = cur.branches[idx];
    }
    cur.end += 1;
    cur.str = str;
  }
}
```
