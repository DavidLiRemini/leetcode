
/*
��̬�滮
����N��Ԫ�ص�����a���ҳ�i,j
ʹ��0�� i < j < N������a[j] - a[i]��ֵ���
*/
class Solution {
public:
    int maxProfit(vector<int> &prices) {
		if (prices.size() <= 1) return 0;
		
        int profit = INT_MIN;
		int minPrice = prices[0];
		for (int i = 1; i < prices.size(); ++i) {
			int tmpProfit = prices[i] - minPrice;
			profit = max(profit, tmpProfit);
			minPrice = min(minPrice, prices[i]);		
		}
		
		return max(profit, 0);
    }
};