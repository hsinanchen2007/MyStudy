This solution uses backtracking search.
First build a Hashmap mapping the first two letters of all available allowed strings to the list of all possible third letter. Then, starting from the very bottom, we first try to build the above level by searching exhaustively through the map, and recursively call the same function on the next level. If false is returned, we try another combination, otherwise we can simply end the search and return true, since that indicates we have reached the top. The base case is when the input string has length 1, we return true.
```import javafx.util.Pair;
class Solution {
    HashMap<Pair<Character,Character>,List<Character>> map = new HashMap<>();
    private boolean backtrack(String s){
        if (s.length() == 1){
            return true;
        }
        char [] arr = new char[s.length()-1];
        int [] indTracker = new int[s.length()-1];
        int currPosition = 0;
        int currPosInd = 0;
        String next = "";
        for (int i=0; i<indTracker.length; i++){
            Pair pair = new Pair(s.charAt(i),s.charAt(i+1));
            if (map.containsKey(pair)){
                arr[i] = map.get(pair).get(0);
            }else{
                return false;
            }
        }
        
        while(currPosition < arr.length){
            if (backtrack(new String(arr))){return true;}
            else{
                while(currPosition < arr.length){
                    currPosInd++;
                    List<Character> list = map.get(new Pair<Character,Character>(s.charAt(currPosition),s.charAt(currPosition+1)));
                    if (currPosInd >= list.size()){
                        currPosition++;
                        currPosInd = 0;
                    }else{
                        arr[currPosition] = list.get(currPosInd);
                        break;
                    }
                }
            }
            
        }
        
        return false;
        
    }
    public boolean pyramidTransition(String bottom, List<String> allowed) {
        for (String s : allowed){
            char [] arr = s.toCharArray();
            boolean ve = arr[0] < arr[1];
            Pair<Character,Character> pair = new Pair<>(arr[0],arr[1]);
            if(!map.containsKey(pair)){
                map.put(pair,new ArrayList<Character>());
            }
            map.get(pair).add(arr[2]);
        }
        
        return backtrack(bottom);
    }
}
```