每次加点的范围就是当前位置+1，2，3
判断加了点划分出来的数字是否在0到255之中
判断接下来的数字还够不够点来划分，一个点最多可以划分6个数字，2个点9个
判断划出来的数字是否合法，像010这种0开头的非0数字就不合法，去掉它
接下来就是回溯模板代码

    public List<String> restoreIpAddresses(String s) {
        List<String> list = new ArrayList();
        backTrack(list, new ArrayList<Integer>(), s, 0);
        return list;
    }

    void backTrack(List<String> list, List<Integer> indexList, String s, int start){
        if(indexList.size()==3){
            int temp = Integer.valueOf(s.substring(start, s.length()));
            if(temp>=0 && temp<=255 && String.valueOf(temp).equals(s.substring(start,s.length()))){
                StringBuffer newStr = new StringBuffer(s);
                newStr.insert(indexList.get(2), ".");
                newStr.insert(indexList.get(1), ".");
                newStr.insert(indexList.get(0), ".");
                list.add(newStr.toString());
            }
            return ;
        }

        for(int step=1; step<=3 && start+step<s.length(); step++){
            int temp = Integer.valueOf(s.substring(start,start+step));
            int restNeedNums = 3 - indexList.size();
            if(temp>=0 && temp<=255 && 3*restNeedNums>=s.length()-start-step && String.valueOf(temp).equals(s.substring(start,start+step))){
                indexList.add(start+step);
                backTrack(list, indexList, s, start+step);
                indexList.remove(indexList.size()-1);
            }
        }   
    }