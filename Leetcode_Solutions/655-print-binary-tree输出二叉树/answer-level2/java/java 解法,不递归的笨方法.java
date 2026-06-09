 // 第一步:利用标准的BFS算法遍历整个树,树如果是空的,就补齐 ,把整个树全部补满
//第二步:补满的树,按照题目的要求输出.
//公式是:开头空出的是 总数/2 ,每一行都一直除2 
//开头以后空出的是当前数字往后走2n+1 ,n是上一次空出的值,从0开始,最后一行空1,倒数第二行空3,第三行空7,第四行空15


public List<List<String>> printTree(TreeNode root) {
        List<List<String>> printTree = new ArrayList<List<String>>();
        if (root == null) {
            return printTree;
        }

        Queue<TreeNode> qe = new LinkedList<TreeNode>();
        qe.add(root);
        int countall = 0;
        int countcur = 0;
        int countnull = 0;
        int layer = 0;
        ArrayList<ArrayList<String>> all = new ArrayList<ArrayList<String>>();
        ArrayList<String> cural = new ArrayList<String>();
        while (!qe.isEmpty()) {
            TreeNode cu = qe.poll();
            
            if (countcur >= Math.pow(2, layer)) {
                if(countnull>=Math.pow(2, layer)) {
                    break;
                }else{
                    countnull=0;  
                }
                layer++;
                countall = countall+countcur;
                countcur = 0;       
                all.add(cural);
                cural = new ArrayList<String>();
            }
            //System.out.println("当前层高:" + layer +  "总:" + countall+ "当前:" + countcur + "当前null:" + countnull +"当前值:" + cu.val);
            cural.add(""+cu.val);
            countcur++;
            if(cu.val==Integer.MAX_VALUE) {
                countnull++;   
            }
        
            // 遍历
            if (cu.left != null) {
                qe.add(cu.left);

            } else {
                // 人为创造一个空节点
                TreeNode trnull = new TreeNode(Integer.MAX_VALUE);
                qe.add(trnull);

            }

            if (cu.right != null) {
                qe.add(cu.right);
            } else {
                // 人为创造一个空节点
                TreeNode trnull = new TreeNode(Integer.MAX_VALUE);
                qe.add(trnull);
            }

        }

        
        
     List<List<String>> allv = new ArrayList<List<String>>();
     List<String> curalv = new ArrayList<String>();
        int front = countall;
        
        if(all.size()<1) {
        	
        }
        int med = 0;
        for(int i =0 ; i<all.size() ;i++) {
        	med = 2*med+1;
        }
        
        
        for(int i =0 ; i<all.size() ;i++) {
        	front = front/2;
            int count = 0;
            int frontcount=0;
        	ArrayList<String> cu = all.get(i);
        	
            int tempcc  = 0;
        	allv.add(curalv);
        	for(int j =0 ; j< countall ; j++) {
        		if(j==front) {
        			if(Integer.valueOf(cu.get(count))!=Integer.MAX_VALUE){
                       curalv.add(cu.get(count));  
                    }else{
                      curalv.add("");  
                    }
                    tempcc = j;
        			count++;
        		}else if(count!=0&&count<cu.size()&&j-tempcc==med+2) {
        			if(Integer.valueOf(cu.get(count))!=Integer.MAX_VALUE){
                       curalv.add(cu.get(count));  
                    }else{
                      curalv.add("");  
                    }
                    
                    
                    
                    count++;
                    tempcc = j;
        		}else {
        			curalv.add("");
        		}
        	}
        	curalv = new ArrayList<String>();
            med = med/2-1;
        }
           

//        System.out.println(countall);
//        for(List<String> cu: allv) {
//        	String cus = "";
//        	for(String temp:cu) {
//        		cus = cus+" "+temp;	
//        	}
//        	System.out.println(cus);
//        }
        
        
        
        

        return allv;
    }