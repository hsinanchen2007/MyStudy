![image.png](https://pic.leetcode-cn.com/ef93c0a282b48dff14b7641c4c9818438e687f8b865e85cf5b5600605da95a20-image.png)
public class Solution0127 {
	public static void main(String[] args) {
		Solution0127 solution0127 = new Solution0127();
		String beginWord = "a";
		String endWord = "c";
		List<String> wordList = Arrays.asList("a","b","c");
		System.out.println(solution0127.ladderLength(beginWord, endWord, wordList));
	}
	int min;
	public int ladderLength(String beginWord, String endWord, List<String> wordList) {
		if(beginWord.equals(endWord)) {
			return 1;
		}
		int size = wordList.size();
		min = size + 1;
		int[][] graph1 = new int[size][size];		
		for(int i = 0 ; i < size; i++) {
			for(int j = i + 1; j < size; j++) {
				if(isNext(wordList.get(i), wordList.get(j))) {
					graph1[i][j] = 1;
					graph1[j][i] = 1;
				}
			}
		}
		Graph graph = new Graph(size);
		ArrayList<Node127> arr = graph.arr;
		for(int i = 0 ; i < size; i++) {
			Node127 n = arr.get(i);
			for(int j = 0; j < size; j++) {
				if(j != i && isNext(wordList.get(i), wordList.get(j))) {
					Node127 n1 = new Node127(j);
					n.next = n1;
					n = n1;
				}
			}
		}
		for(int i = 0; i < size; i++) {
			String string = wordList.get(i);
			if(isNext(beginWord, string)) {
				if(string.equals(endWord)) {
					return 2;
				}
				min = Math.min(min, BFS(graph, wordList, endWord, i));
			}
		}
		return min == size + 1? 0 : min;
	}
	public int BFS(Graph graph, List<String> worList, String endWord, int index) {
		boolean[] visited = new boolean[worList.size()];
		visited[index] = true;
		int depth = 3;
		Queue<Integer> queue = new LinkedList<Integer>();
		queue.add(index);
		while(!queue.isEmpty()) {
			int size = queue.size();
			while(size-- > 0) {
				index = queue.poll();
				Node127 n = graph.arr.get(index);
				n = n.next;
				while (n != null) {
					if(!visited[n.index]) {
						queue.add(n.index);
						visited[n.index] = true;
					}
					if(worList.get(n.index).equals(endWord)) {
						return depth;
					}
					n = n.next;
				}
			}
			depth++;
		}
		return depth;
	}
	public boolean isNext(String s1, String s2) {
		int diff = 0;
		if(s1.equals(s2)) {
			return false;
		}
		for(int i = 0; i < s1.length(); i++) {
			if(s1.charAt(i) != s2.charAt(i)) {
				diff++;
			}
			if(diff > 1) {
				return false;
			}
		}
		return true;
	}
}
class Node127{
	int index;
	Node127 next;
	public Node127(int v) {
		this.index = v;
	}
}
class Graph{
	ArrayList<Node127> arr;
	public Graph(int size) {
		arr = new ArrayList<Node127>();
		for(int i = 0; i < size; i++) {
			arr.add(new Node127(i));
		}
	}
}
