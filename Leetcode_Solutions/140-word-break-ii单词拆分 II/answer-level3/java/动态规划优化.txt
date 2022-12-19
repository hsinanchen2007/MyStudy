第一版 代码超时及其原因
超时代码，dp MAP在key接近s.length()的List中存在大量可到达末尾的路径，对该数组进行遍历耗时巨长
```
class Solution {
    public List<String> wordBreak(String s, List<String> wordDict) {
    	List<String> res = new LinkedList<>();
        if(wordDict.size() == 0) return res;
        
    	HashSet<String> dictSet = new HashSet<>();
        HashSet<Character> charSet = new HashSet<>();
    	int minWordLen = 0,maxWordLen = 0;
    	for(String word: wordDict) {
    		if(minWordLen == 0) minWordLen = word.length();
    		if(minWordLen > word.length()) minWordLen = word.length();
    		if(maxWordLen == 0) maxWordLen = word.length();
    		if(maxWordLen < word.length()) maxWordLen = word.length();
    		for(char c: word.toCharArray()){
                if(!charSet.contains(c))
                	charSet.add(c);
            }
    		dictSet.add(word);
    	}
    	//抖机灵
        for(int i = 0; i < s.length(); i++){
            if(!charSet.contains(s.charAt(i)))
                return res;
        }
    	
    	HashMap<Integer,LinkedList<String>> dp = new HashMap<>();
    	LinkedList<Integer> keyList = new LinkedList<>();
    	
    	dp.put(-1, new LinkedList<String>());
    	dp.get(-1).add("");
    	
    	StringBuilder outerSb = new StringBuilder();
    	int i = minWordLen-1;
		outerSb.append(s.substring(0, i));
    	for(; i < s.length() - minWordLen; i++) {
    		//删除过期记录，防止JVM堆溢出
    		if(i > maxWordLen) {
    			dp.remove(i-maxWordLen-1);
    		}
    		outerSb.append(s.charAt(i));
    		if(dictSet.contains(outerSb.toString())) {
    			dp.put(i, new LinkedList<>());
    			dp.get(i).add(outerSb.toString()+" ");
    		}
			for(int j: keyList) {
				if(dictSet.contains(outerSb.substring(j+1))) {
					if(!dp.containsKey(i))
						dp.put(i, new LinkedList<>());
                    //当j接近s.length()时，该List巨长，会导致内存溢出和超时的风险
                    //这是本方法最大的问题所在
					for(String beforeStr: dp.get(j)) {   
						dp.get(i).add(beforeStr+outerSb.substring(j+1)+" ");
					}
				}
			}
			if(dp.containsKey(i))
				keyList.add(i);
    	}
    	for(String word: dictSet) {
    		int index = s.length()-word.length();
    		if(dp.containsKey(index-1) && s.substring(index).equals(word)) {
    			for(String beforeStr: dp.get(index-1)) {
    				res.add(beforeStr+word);
    			}
    		}
    	}
    	
    	return res;
    }
}
```
第二版,总算不超时了
先找出动态规划在s中可到达的位置 dpPointList
依次在dpPointList中寻找可将s分割完整的word最后将其空格拼接，存入res中
```
class Solution {
	private LinkedList<Integer> dpPointList = new LinkedList<>();
	private HashSet<String> dictSet = new HashSet<>();
	private List<String> res = new LinkedList<>();
	private int minWordLen = 0;
	private int maxWordLen = 0;
	
	public List<String> wordBreak(String s, List<String> wordDict) {
		dpPointList = new LinkedList<>();
		dictSet = new HashSet<>();
		res = new LinkedList<>();
        if(wordDict.size() == 0) return res;
        
        HashSet<Character> charSet = new HashSet<>();
    	for(String word: wordDict) {
    		if(minWordLen == 0) minWordLen = word.length();
    		if(minWordLen > word.length()) minWordLen = word.length();
    		if(maxWordLen == 0) maxWordLen = word.length();
    		if(maxWordLen < word.length()) maxWordLen = word.length();
    		for(char c: word.toCharArray()){
                if(!charSet.contains(c))
                	charSet.add(c);
            }
    		dictSet.add(word);
    	}
    	//抖机灵
        for(int i = 0; i < s.length(); i++){
            if(!charSet.contains(s.charAt(i)))
                return res;
        }
    	
		//正文代码，上面全为预处理
    	int i = minWordLen-1;
		boolean flag = false;
    	for(; i < s.length(); i++) {
    		if(dictSet.contains(s.substring(0,i+1))) {
    			dpPointList.add(i);
    			continue;
    		}
			for(int j: dpPointList) {
				if(j < i && dictSet.contains(s.substring(j+1,i+1))) {
					flag = true;
					break;
				}
			}
			if(flag) {
				dpPointList.add(i);
				flag = false;
			}
    	}
    	if(dpPointList.size() > 0 && dpPointList.getLast() != s.length()-1) return res;

    	//公式为 f[n] = f[n-1] + s.substring(f[n-1]+1,f[n])
    	subEachWord(s,"");
    	return res;
    }
    
    //这里用了String而非StringBuilder主要是用了String值传递得原理
    public void subEachWord(String s, String centence) {
		for(int p: dpPointList) {
			if(p < s.length()) {
				if(s.substring(p+1).isEmpty() && dictSet.contains(s.substring(0,p+1))){
		    		centence = s+(centence.isEmpty()?"":" "+centence); 
		    		res.add(centence);
		    		continue;
				}
		    	if(dictSet.contains(s.substring(p+1))) {
					subEachWord(s.substring(0,p+1),s.substring(p+1)+(centence.isEmpty()?"":" "+centence));
				}
			}
		}
    }
}
```
