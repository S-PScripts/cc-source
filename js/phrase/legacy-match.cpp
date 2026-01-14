function processMatch()
{
////// START

/////////////////////////////////////////////////////////////////////////////
// ProcessMatch
// Process match and compile results
/////////////////////////////////////////////////////////////////////////////
int CPhraseMatcher::ProcessMatch(CStringW &strPhrase, int iThreshold, vector<Results> &ResultVec)
{
    map<int, int> ResultsMap;
    // first do word matching
    int iCurPos = 0;
    CStringW strToken = strPhrase.Tokenize(WordD
                    ResultsMap[it2->first] = 1;
                }
            }
/////////////////////////////////////////////////////////////////////////////
// ProcessMatch
// Process match and compile results
/////////////////////////////////////////////////////////////////////////////
int CPhraseMatcher::ProcessMatch(CStringW &strPhrase, int iThreshold, vector<Results> &ResultVec)
{
    map<int, int> ResultsMap;
    // first do word matching
    int iCurPos = 0;
    CStringW strToken = strPhrase.Tokenize(WordDelimiters(), iCurPos);
    while (!strToken.IsEmpty())
    {
        CStringW strWord;
        strWord.AppendFormat(L" %s ", strToken);
        tMapVec::iterator it = m_WordMap.find(strWord);
        if (it != m_WordMap.end())
        {
            Results Res;
            Res.m_iPhraseIndex = it->second.begin()->first;
            Res.m_iConfidence = 100;
            ResultVec.push_back(Res);
            return 100;
        }
        strToken = strPhrase.Tokenize(WordDelimiters(), iCurPos);
    }

    // now match trigrams
    map<CStringW, int> UniqueTrigrams;
    int iLen = strPhrase.GetLength();
    if (iLen >= 3)
    {
        // compute trigrams
        for (int n = 0; n < iLen - 2; n++)
        {
            CStringW strTri = strPhrase.Mid(n, 3);
            UniqueTrigrams[strTri] = 1;
        }
    }

    int iTriCount = UniqueTrigrams.size();
    map<CStringW, int>::iterator itMap = UniqueTrigrams.begin();
    for (; itMap != UniqueTrigrams.end(); ++itMap)
    {
        tMapVec::iterator it = m_TrigramMap.find(itMap->first);
        if (it != m_TrigramMap.end())
        {
            map<int, int>::iterator it2 = it->second.begin();
            for (; it2 != it->second.end(); ++it2)
            {
                map<int, int>::iterator it3 = ResultsMap.find(it2->first);
                if (it3 != ResultsMap.end())
                {
                    ResultsMap[it2->first]++;
                }
                else
                {
                    ResultsMap[it2->first] = 1;
                }
            }
        }
    }

    // print out results
    TRACE("Input Phrase: t=%d [%S]\n", iTriCount, strPhrase);
    TRACE("Results:\n");
    TRACE("========\n");
    map<int, int>::iterator it4 = ResultsMap.begin();
    int iMatchIndex = 0;
    for (; it4 != ResultsMap.end(); ++it4)
    {
        int iMatch = it4->second * 100 / m_PhraseVector[it4->first].m_iTriGramCount;
        if (iMatch >= iThreshold)
        {
            Results Res;
            Res.m_iPhraseIndex = it4->first;
            Res.m_iConfidence = iMatch;
            ResultVec.push_back(Res);
            TRACE("%d) c=%d t=%d [%S] {%d%%}\n", it4->first, it4->second, m_PhraseVector[it4->first].m_iTriGramCount, m_PhraseVector[it4->first].m_strPhrase, iMatch);
        }
    }
    return iTriCount;
}
elimiters(), iCurPos);
    while (!strToken.IsEmpty())
    {
        CStringW strWord;
        strWord.AppendFormat(L" %s ", strToken);
        tMapVec::iterator it = m_WordMap.find(strWord);
        if (it != m_WordMap.end())
        {
            Results Res;
            Res.m_iPhraseIndex = it->second.begin()->first;
            Res.m_iConfidence = 100;
            ResultVec.push_back(Res);
            return 100;
        }
        strToken = strPhrase.Tokenize(WordDelimiters(), iCurPos);
    }

    // now match trigrams
    map<CStringW, int> UniqueTrigrams;
    int iLen = strPhrase.GetLength();
    if (iLen >= 3)
    {
        // compute trigrams
        for (int n = 0; n < iLen - 2; n++)
        {
            CStringW strTri = strPhrase.Mid(n, 3);
            UniqueTrigrams[strTri] = 1;
        }
    }

    int iTriCount = UniqueTrigrams.size();
    map<CStringW, int>::iterator itMap = UniqueTrigrams.begin();
    for (; itMap != UniqueTrigrams.end(); ++itMap)
    {
        tMapVec::iterator it = m_TrigramMap.find(itMap->first);
        if (it != m_TrigramMap.end())
        {
            map<int, int>::iterator it2 = it->second.begin();
            for (; it2 != it->second.end(); ++it2)
            {
                map<int, int>::iterator it3 = ResultsMap.find(it2->first);
                if (it3 != ResultsMap.end())
                {
                    ResultsMap[it2->first]++;
                }
                else
                {
                    ResultsMap[it2->first] = 1;
                }
            }/////////////////////////////////////////////////////////////////////////////
// ProcessMatch
// Process match and compile results
/////////////////////////////////////////////////////////////////////////////
int CPhraseMatcher::ProcessMatch(CStringW &strPhrase, int iThreshold, vector<Results> &ResultVec)
{
    map<int, int> ResultsMap;
    // first do word matching
    int iCurPos = 0;
    CStringW strToken = strPhrase.Tokenize(WordDelimiters(), iCurPos);
    while (!strToken.IsEmpty())
    {
        CStringW strWord;
        strWord.AppendFormat(L" %s ", strToken);
        tMapVec::iterator it = m_WordMap.find(strWord);
        if (it != m_WordMap.end())
        {
            Results Res;
            Res.m_iPhraseIndex = it->second.begin()->first;
            Res.m_iConfidence = 100;
            ResultVec.push_back(Res);
            return 100;
        }
        strToken = strPhrase.Tokenize(WordDelimiters(), iCurPos);
    }

    // now match trigrams
    map<CStringW, int> UniqueTrigrams;
    int iLen = strPhrase.GetLength();
    if (iLen >= 3)
    {
        // compute trigrams
        for (int n = 0; n < iLen - 2; n++)
        {
            CStringW strTri = strPhrase.Mid(n, 3);
            UniqueTrigrams[strTri] = 1;
        }
    }

    int iTriCount = UniqueTrigrams.size();
    map<CStringW, int>::iterator itMap = UniqueTrigrams.begin();
    for (; itMap != UniqueTrigrams.end(); ++itMap)
    {
        tMapVec::iterator it = m_TrigramMap.find(itMap->first);
        if (it != m_TrigramMap.end())
        {
            map<int, int>::iterator it2 = it->second.begin();
            for (; it2 != it->second.end(); ++it2)
            {
                map<int, int>::iterator it3 = ResultsMap.find(it2->first);
                if (it3 != ResultsMap.end())
                {
                    ResultsMap[it2->first]++;
                }
                else
                {
                    ResultsMap[it2->first] = 1;
                }
            }
        }
    }

    // print out results
    TRACE("Input Phrase: t=%d [%S]\n", iTriCount, strPhrase);
    TRACE("Results:\n");
    TRACE("========\n");
    map<int, int>::iterator it4 = ResultsMap.begin();
    int iMatchIndex = 0;
    for (; it4 != ResultsMap.end(); ++it4)
    {
        int iMatch = it4->second * 100 / m_PhraseVector[it4->first].m_iTriGramCount;
        if (iMatch >= iThreshold)
        {
            Results Res;
            Res.m_iPhraseIndex = it4->first;
            Res.m_iConfidence = iMatch;
            ResultVec.push_back(Res);
            TRACE("%d) c=%d t=%d [%S] {%d%%}\n", it4->first, it4->second, m_PhraseVector[it4->first].m_iTriGramCount, m_PhraseVector[it4->first].m_strPhrase, iMatch);
        }
    }
    return iTriCount;
}

        }
    }

    // print out results
    TRACE("Input Phrase: t=%d [%S]\n", iTriCount, strPhrase);
    TRACE("Results:\n");
    TRACE("========\n");
    map<int, int>::iterator it4 = ResultsMap.begin();
    int iMatchIndex = 0;
    for (; it4 != ResultsMap.end(); ++it4)
    {
        int iMatch = it4->second * 100 / m_PhraseVector[it4->first].m_iTriGramCount;
        if (iMatch >= iThreshold)
        {
            Results Res;
            Res.m_iPhraseIndex = it4->first;
            Res.m_iConfidence = iMatch;
            ResultVec.push_back(Res);
            TRACE("%d) c=%d t=%d [%S] {%d%%}\n", it4->first, it4->second, m_PhraseVector[it4->first].m_iTriGramCount, m_PhraseVector[it4->first].m_strPhrase, iMatch);
        }
    }

    return iTriCount;
}


//    trigramMap
//    vectorMap
//
//    struct Results
//    {
//        int m_iPhraseIndex;
//        int m_iConfidence;
//    };
//
//    struct PhraseInfo
//    {
//        CStringW m_strPhrase;
//        CStringW m_strDescription;
//        Phrase_priority m_Priority;
//        DWORD m_dwCategory;
//        int m_iTriGramCount;
//    };
//
//    private:
//        typedef  map<CStringW, map<int, int>> tMapVec;
//        vector<PhraseInfo> m_PhraseVector;
//        tMapVec m_TrigramMap;
//        tMapVec m_WordMap;
