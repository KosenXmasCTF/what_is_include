FROM centos:centos7

RUN yum -y install openssh-server passwd gcc; yum clean all

RUN ssh-keygen -A

RUN useradd guest -m

RUN echo "guest" | passwd --stdin guest

# RUN echo "/home/guest/what_is_include; exit" > /home/guest/.bashrc
# RUN chmod 555 /home/guest/.bashrc

ADD ./what_is_include /home/guest/what_is_include
ADD ./flag_irjblwgqbd.txt /home/guest/flag_irjblwgqbd.txt

RUN chmod 555 /home/guest/what_is_include
RUN chmod 444 /home/guest/flag_irjblwgqbd.txt

RUN chsh -s /home/guest/what_is_include guest 

RUN chown root:root /home/guest
RUN chmod 2555 /home/guest

ENTRYPOINT ["/sbin/sshd", "-D"]



