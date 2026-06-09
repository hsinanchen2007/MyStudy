c#  用Dictionary遍历， 
一，设计transcation类对象，把数据split放入transcation类，建立Dictionary<transcation>对比集
二，遍历判断每个数据，
①对比集中存在该名称的交易，遍历对比集，检查交易间隔时间问题，数据非法且未被标记，则标记未被标记的非法遍历数据，非法遍历对比集数据，扔入结果集，结束
②不存在，略过间隔问题，处理金额超出问题，数据非法且未被标记，标记非法扔入结果集，
③数据按名称放入对比集
三，输出结果

    public IList<string> InvalidTransactions(string[] transactions)
    {         
        IList<string> res = new List<String>();
        if (transactions.Length > 1000)
            return res;

        Dictionary<string, List<Transaction>> dic = new Dictionary<string, List<Transaction>>();
        foreach (string item in transactions)
        {
            Transaction txnData = Transaction.ConvertTxn(item);
            //①检查是否对比集中存在数据, 如果存在遍历重名交易，如果不存在，没有时间间隔错误
            //②判断时间间隔错误，检查非法标记，如果合法扔进结果集并标记非法结果
            if (dic.ContainsKey(txnData.name))
            {
                foreach (Transaction subTxn in dic[txnData.name])
                {
                    if (Math.Abs((txnData.time - subTxn.time)) <= 60 && txnData.city != subTxn.city)
                    {
                        if (subTxn.isValidTxn)
                        {
                            res.Add(subTxn.resStr);
                            subTxn.isValidTxn = false;
                        }

                        if (txnData.isValidTxn)
                        {
                            res.Add(txnData.resStr);
                            txnData.isValidTxn = false;
                        }
                    }  
                }
                if (txnData.isValidTxn)
                    dic[txnData.name].Add(txnData);                     
            }
            //①判断金额数值非法，金额超出并且未被标记加入过结果集，扔入结果集并标记非法
            if (txnData.amount > 1000 && txnData.isValidTxn)
            {
                res.Add(txnData.resStr);
                txnData.isValidTxn = false;
            }
            //数据按名称扔入对比集
            if (dic.ContainsKey(txnData.name))
                dic[txnData.name].Add(txnData);
            else
                dic.Add(txnData.name, new List<Transaction> { txnData });
        }    
        return res;
    }

    public class Transaction 
        {
            public string name;
            public int time;
            public decimal amount;
            public string city;
            public bool isValidTxn;
            public string resStr;
            public static Transaction ConvertTxn(String txn)
            {
                string[] str = txn.Split(',');
                Transaction data = new Transaction();
                data.city = str[3];
                if (!Decimal.TryParse(str[2], out data.amount))
                    data.amount = 0m;
                if (!Int32.TryParse(str[1], out data.time))
                    data.time = 0;
                data.name = str[0];
                data.isValidTxn = true;
                data.resStr = txn;
                return data;
            }
        }
