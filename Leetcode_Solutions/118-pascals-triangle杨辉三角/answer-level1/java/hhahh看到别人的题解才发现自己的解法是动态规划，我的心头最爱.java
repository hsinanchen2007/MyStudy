    class Solution {
        public List<List<Integer>> generate(int numRows) {
            List<List<Integer>> res = new ArrayList<>();

            if(numRows == 0)
                return res;

            for(int i = 0; i < numRows; i++){
                res.add(new ArrayList<>());
                for(int j = 0; j <= i; j++){
                    if(j == 0 || j == i)
                        res.get(i).add(1);
                    else
                        res.get(i).add(res.get(i-1).get(j-1)+res.get(i-1).get(j));
                }
            }

            return res;
        }
    }