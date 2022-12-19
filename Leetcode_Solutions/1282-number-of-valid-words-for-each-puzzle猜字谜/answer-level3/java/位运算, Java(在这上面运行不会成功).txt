首先,java解这个题可能解不出来,或者需要写大量的代码
从a-z 26个字母 每个字母是否存在用1位来表示 所以每个字符串都能用一个int类型表示
两种解法:
1, 每个遍历一次
时间复杂度n^2 测试根本过不了超时...
2, map映射
那选什么样的map呢
数组映射: 由于words中字符长度50>26 最大可能有2^26 种结果 那意味着要申请2^26长度的数组 但是空间超了 不成功
map[key-value]映射: 选HashMap?那么需要多大长度? 2^26方肯定超,那选小一点?可是一旦HashMap发生扩容肯定会超时
所以要自己手写HashMap 那么这样就需要很大工作量.
贴上2的解法代码:
public List<Integer> findNumOfValidWords(String[] words, String[] puzzles) {
        int[] includeWord = new int[297795585];//2的人26次方+1
        List<Integer> counts = new LinkedList<>();

        for (int i = 0; i < words.length; i++) {
            int res = 0;
            String word = words[i];
            for (int j = 0; j < word.length(); j++){
                res|=(1<<(word.charAt(j)-'a'));
            }
            includeWord[res] += 1;
        }

        for (int i = 0; i < puzzles.length; i++) {
            int count = 0, res = 0;
            String puzzle = puzzles[i];
            int first = 1<<(puzzle.charAt(0)-'a');

            for (int k = 0; k < puzzle.length(); k++){
                res|=(1<<(puzzle.charAt(k)-'a'));
            }

            for (int j = res; j != 0; j=(j-1)&res){//自己手动计算一下就懂了 好难解释
                if ((j&first) != 0) {
                    count+=includeWord[j];
                }
            }
            counts.add(count);
        }
        return counts;
    }

1的解法:
public List<Integer> findNumOfValidWords(String[] words, String[] puzzles) {
        int[] includePuzzle = new int[puzzles.length];
        int[] includeWord = new int[words.length];
        List<Integer> counts = new LinkedList<>();

        for (int i = 0; i < words.length; i++) {
            int res = 0;
            String word = words[i];
            for (int j = 0; j < word.length(); j++){
                res|=(1<<(word.charAt(j)-'a'));
            }
            includeWord[i] = res;
        }

        for (int i = 0; i < puzzles.length; i++) {
            int count = 0;
            String puzzle = puzzles[i];
            int first = 1<<(puzzle.charAt(0)-'a');
            for (int j = 0; j < words.length; j++){
                if ((first&includeWord[j]) != 0) {
                    if (includePuzzle[i] == 0){
                        int res = 0;
                        for (int k = 0; k < puzzle.length(); k++){
                            res|=(1<<(puzzle.charAt(k)-'a'));
                        }
                        includePuzzle[i] = res;
                    }
                    if ((includePuzzle[i] & includeWord[j]) == includeWord[j]) {
                        count++;
                    }
                }
            }
            counts.add(count);
        }
        return counts;
    }
