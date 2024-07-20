#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

struct Node {
  Node * links[26];
  int cntEndWith = 0;
  int cntPrefix = 0;

  bool containsKey(char ch) {
    return (links[ch - 'a'] != NULL);
  }
  Node * get(char ch) {
    return links[ch - 'a'];
  }
  void put(char ch, Node * node) {
    links[ch - 'a'] = node;
  }
  void increaseEnd() {
    cntEndWith++;
  }
  void increasePrefix() {
    cntPrefix++;
  }
  int getEnd() {
    return cntEndWith;
  }
  int getPrefix() {
    return cntPrefix;
  }
};
class Trie {
  private:
    Node * root;

  public:
    /** Initialize your data structure here. */
    Trie() {
      root = new Node();
    }

  /** Inserts a word into the trie. */
  void insert(string word) {
    Node * node = root;
    for (int i = 0; i < word.length(); i++) {
      if (!node -> containsKey(word[i])) {
        node -> put(word[i], new Node());
      }
      node = node -> get(word[i]);
      node -> increasePrefix();
    }
    node -> increaseEnd();
  }


    string prefix(string word)
    {
        Node *node = root;
        int i = 0;
        string str = "";
        if (word.size() == 0)
            return str;
        while (i < word.length())
        {

            if (node->containsKey(word[i]))
            {

                str += word[i];
            }
            node = node->get(word[i]);
            if (node->getPrefix() == 1)
            {
                return str;
            }
            i++;
        }
        return str;
    }
};

vector<string> findPrefixes(string arr[], int n)
{
    Trie trie;
    for (int i = 0; i < n; i++)
    {
        trie.insert(arr[i]);
    }
    vector<string> res;
    for (int i = 0; i < n; i++)
    {
        res.push_back(trie.prefix(arr[i]));
    }
    return res;
}
void solve()
{
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll test = 1;
    // cin>>test;
    while (test--)
    {
        solve();
    }
    return 0;
}
