class Solution {
    public int[] maxDepthAfterSplit(String seq) {
if(seq==null) {
    			return new int[0];
    		}
    		int [] arr = new int[seq.length()];
    		Stack<Integer> set =new Stack<Integer>();
    		for(int i=0;i<arr.length;i++) {
    			if(seq.charAt(i)=='(') {
    				set.push(i);
    			}else {
    			int j = set.size();
    			int left = set.pop();
    			if(j%2==0) {
    				arr[left]=1;
    				arr[i]=1;
    			}
    			}
    		}

    		return arr;

    }
}