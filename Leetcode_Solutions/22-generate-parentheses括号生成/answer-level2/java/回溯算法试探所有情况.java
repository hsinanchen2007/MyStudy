
import java.util.List;

class Solution {
	private List<String> out= new ArrayList<String>();
    public List<String> generateParenthesis(int n) {
    	//通过回溯试探所有情况
    	backtrack("", n, n);
    	return out;
    }
    
    private void backtrack(String oneStr,int left,int right)
    {
    	//先给出结束条件，右括号用完了
    	if(right == 0)
    	{
    		out.add(oneStr);
    		return ;
    	}
    	//给出回溯逻辑，插入左括号试完了，再插入右括号试一下（跟for循环试n种可能是一样的）
    	
    	//可以执行插入左括号往下试的条件，是还有左括号就行
    	if(left >0)
    	{
    		//插入左括号
    		backtrack(oneStr+"(",left -1,right);
    	}
    	
    	//可以执行插入右括号往下试的条件，还有右括号（必然的），同时左括号还有未匹配的
    	if(right > left)
    	{
    		//插入右括号
    		backtrack(oneStr+")",left,right-1);
    	}
    }
}

