使用贪心算法，
找到总和的1/3 targetSum（此时如果不能被3整数，直接返回false），
遍历数组，先找到前两份和为targetSum的数组，剩下的和为targetSum则为true，反之为false。