#include <iostream>
template <typename T>
struct List_node
{
	T data;
	List_node<T>* next;
};

template <typename T>
class List
{
public:
	List()
	{
		m_head = nullptr;
	}
	~List()
	{
		delete m_head;
	}
	void  push_back(const T& indata)
	{
		List_node<T>* node = new List_node<T>;
		node->next = nullptr;
		node->data = indata;
		if (m_head == nullptr)
		{
			m_head = node;
			return;
		}
		List_node<T>* current = m_head;
		while(current->next!=nullptr)
		{
			current = current->next;
		}
		current->next = node;
	}

	void push_front(const T* indata)
	{
		List_node<T>* node = new List_node<T>;
		node->data = nullptr;
		node->data = indata;
		if (m_head == nullptr)
		{
			m_head = node;
			return;
		}
		List_node<T>* current = m_head;
		m_head = node;
		m_head->next = current;
	}

	void insert(List_node<T>* from, List_node<T>* list_to_be_added)
	{
		List_node<T>* current = m_head;
		if (current == from) // if from the beginning
		{
			m_head = from;
			m_head->next = current;
			return;
		}

			while (current != from) // finde where to insert
			{
				current = current->next;
			}
			
		if (current->next->next == nullptr) // if from the end
		{
			current->next = from;
			return;
		}
		List_node<T>* tmp = current->next;
		current = list_to_be_added;
		while (current->next != nullptr)
		{
			current = current->next;
		}
		current = tmp;
	}

	void pop_back()
	{
		List_node<T>* current = m_head;
		while (current->next->next != nullptr)
		{
			current = current->next;
		}
		delete current->next;
		current->next = nullptr;
	}


	void pop_front()
	{
		List_node<T>* current = m_head->next;
		m_head->next = nullptr;
			delete m_head;
			m_head = current;
	}

	List_node <T>* Begin() const
	{
		return m_head;
	}
	List_node <T>* End() const
	{
		List_node<T>* current = m_head;
		while (current->next != nullptr)
		{
			current = current->next;
		}
		
		return current;
	}

private:
	List_node <T>* m_head;
};

int main()
{
	List<int> obj;
	obj.push_back(5);
	obj.push_back(6);
	obj.push_back(18);
	obj.push_back(68);
	obj.push_back(58);
	obj.push_back(48);
	List<int> obj2;
	obj2.push_back(55);
	obj2.push_back(66);
	obj2.push_back(77);
	auto from = obj.Begin()->next->next;
	obj.insert(from, obj2.Begin());
	std::cout << "Done!\n";
}

